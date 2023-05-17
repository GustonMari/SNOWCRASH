We see that level13 is a binary, when you try to execute this binary
you have : UID 2013 started us but we we expect 4242.
So we can imagine that we have to change our UID to 4242.
To investigate, we use ghidra to convert this binary into a c file.

void main(void)
{
  __uid_t _Var1;
  undefined4 uVar2;
  
  _Var1 = getuid();
  if (_Var1 != 0x1092) {
    _Var1 = getuid();
    printf("UID %d started us but we we expect %d\n",_Var1,0x1092);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  uVar2 = ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
  printf("your token is %s\n",uVar2);
  return;
}

So we had the good intuitive idea !!

try to change the UID :
#include <unistd.h>

int main()
{
	setuid(0x1092);
	execl("/home/user/level13", "level13", NULL);
	return (0);
}

It's not working...
After some research we found that it's hard to change the UID without the sudo rights (su usermod -u 4242 your_username).

Another way is to change the value of the UID directly in the function with gdb !!!
So we have to find this line : if (_Var1 != 0x1092)
to change the value of the variable to 0x1092
So let's do this !

https://www.cs.swarthmore.edu/~newhall/cs31/resources/ia32_gdb.php
https://habr.com/en/articles/551500/

gdb level13

(gdb) disass main --> we see all the functions in asm of the main function

Dump of assembler code for function main:
0x0804858c <+0>:	push   %ebp
0x0804858d <+1>:	mov    %esp,%ebp
0x0804858f <+3>:	and    $0xfffffff0,%esp
0x08048592 <+6>:	sub    $0x10,%esp
0x08048595 <+9>:	call   0x8048380 <getuid@plt>
0x0804859a <+14>:	cmp    $0x1092,%eax				--> we understand that this function compare the variable eax to 0x1092 --> this is the line !!!
0x0804859f <+19>:	je     0x80485cb <main+63>
0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
0x080485a6 <+26>:	mov    $0x80486c8,%edx
0x080485ab <+31>:	movl   $0x1092,0x8(%esp)
0x080485b3 <+39>:	mov    %eax,0x4(%esp)
0x080485b7 <+43>:	mov    %edx,(%esp)
0x080485ba <+46>:	call   0x8048360 <printf@plt>
0x080485bf <+51>:	movl   $0x1,(%esp)
0x080485c6 <+58>:	call   0x80483a0 <exit@plt>
0x080485cb <+63>:	movl   $0x80486ef,(%esp)
0x080485d2 <+70>:	call   0x8048474 <ft_des>
0x080485d7 <+75>:	mov    $0x8048709,%edx
0x080485dc <+80>:	mov    %eax,0x4(%esp)
0x080485e0 <+84>:	mov    %edx,(%esp)
0x080485e3 <+87>:	call   0x8048360 <printf@plt>
0x080485e8 <+92>:	leave  
0x080485e9 <+93>:	ret

(gdb) break *0x0804859a --> so we put a breakpoint on the line we found
(gdb) run --> start the program
Starting program: /home/user/level13/level13
Breakpoint 1, 0x0804859a in main ()
(gdb) display $eax			--> display the variable to see if its the good one
1: $eax = 2013 				--> yes 2013 is our UID
(gdb) set $eax = 4242		--> we set the variable eax from 2013 to 4242
(gdb) display $eax
2: $eax = 4242
(gdb) ni					--> continue to execute, line after line
0x0804859f in main ()
2: $eax = 4242
1: $eax = 4242
(gdb) ni
0x080485cb in main ()
2: $eax = 4242
1: $eax = 4242
(gdb) ni
0x080485d2 in main ()
2: $eax = 4242
1: $eax = 4242
(gdb) ni
0x080485d7 in main ()
2: $eax = 134524936
1: $eax = 134524936
(gdb) ni
0x080485dc in main ()
2: $eax = 134524936
1: $eax = 134524936
(gdb) ni
0x080485e0 in main ()
2: $eax = 134524936
1: $eax = 134524936
(gdb) ni
0x080485e3 in main ()
2: $eax = 134524936
1: $eax = 134524936
(gdb) ni
your token is 2A31L79asukciNyi8uppkEuSx -->printf("your token is %s\n",uVar2); --> Perfect we have our token 