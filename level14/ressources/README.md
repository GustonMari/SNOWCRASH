first we see nothing when we arrived in the level14.
at first we've tried to search for different things we theses commands:

find / -type f -name "*level05*" 2>/dev/null
/etc/group
/etc/passwd
/proc/2671/task/2671/cmdline
/proc/2671/cmdline
/rofs/etc/group
/rofs/etc/passwd
find / -type f -exec grep -l "flag14" {} ; 2>/dev/null

we finish by finding the getflag executable with:
find / -name getflag 2>/dev/null
and we conclued that the exec file was in /bin.

using scp and ghidra we decompilated the file and we found this main (cf getflag.c main).
Our first goal was to unlock the message "Check flag.Here is your token :".
After this we've seen that _Var5 with triggering different fputs
and so printing diffenrent things, we conclued it was the different token
for different level. by analyzing the hex numbers:
https://decimal.info/hex-to-decimal/B/how-to-convert-0XBBE-to-decimal.html
we find a pattern: 3000 + lvlnumber => so for level 14 => 3014

but our strategy didnt work at the begining because a message was triggering by this function:
puts("You should not reverse this");

so we had to change the value of lVar2 to pass it to -1 to 0.
and after same logic as before => change the _Var5

(gdb) b *main+72
Breakpoint 2 at 0x804898e
(gdb) b *main+452
Breakpoint 3 at 0x8048b0a
(gdb) run
Starting program: /bin/getflag 

Breakpoint 1, 0x0804894a in main ()
(gdb) print $eax
$1 = 1
(gdb) s
Single stepping until exit from function main,
which has no line number information.

Breakpoint 2, 0x0804898e in main ()
(gdb) print $eax
$2 = -1
(gdb) set $eax=0 
(gdb) print $eax
$3 = 0
(gdb) s
Single stepping until exit from function main,
which has no line number information.

Breakpoint 3, 0x08048b0a in main ()
(gdb) print $eax
$4 = 2014
(gdb) set $eax=3014
(gdb) s    
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
(gdb) quit

