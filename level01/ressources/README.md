first do: find / -type f -exec grep -l "flag01" {} \; 2>/dev/null

find: It is a command-line utility that is used to search for files and directories within a specified location.
/: It specifies the starting directory for the search. In this case, it is the root directory, which is the top-level directory in a file system.
-type f: It is a find command option that filters the search to only include regular files. It excludes directories, symbolic links, and other special file types.
-exec: It is a find command option used to execute a command on the files found during the search.
grep -l "flag01" {}: It is the command that is executed on each file found by find. grep is a command-line tool for searching patterns in files,
and the -l option is used to print only the names of files that contain the specified pattern, which in this case is "flag01".
The {} is a placeholder that represents each file found by find, and it is replaced with the actual file name.
\;: It is the termination character for the -exec option. It indicates the end of the command to be executed on each file.

2>/dev/null: It is a redirection command that redirects the error output (stderr) to the null device (/dev/null). By doing this, any error messages generated during the execution of the command are discarded and not displayed on the screen.

to search for every string with 'flag01', command return:
/etc/group
/etc/passwd
/proc/7133/task/7133/cmdline
/proc/7133/cmdline
/rofs/etc/group
/rofs/etc/passwd

cat the password in /etc/ you get:
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
we can deduct that 42hDRfypTqqnw is the encrypted password. we then need to break the password

you can now install john the ripper, famous fast password cracker:
https://www.win.tue.nl/~aeb/linux/hh/hh-4.html
https://www.openwall.com/john/

you can copy 'flag01:42hDRfypTqqnw' to crack.txt and then run the command:
john crack.txt --show
Then you will get:
flag01:abcdefg

1 password hash cracked, 0 left
