in this level we have an executable and a token.
the token value is: f4kmm6p|=?p?n??DB?Du{??
and when you write the command ./level09 token you'll get: tpmhr

when you use ./level and some input you'll get different result:
./level09 111111111
123456789:
./level09 ccccccccc
cdefghijk
 so the exec file add the index number to the ascii value of the char.

hexdump -C token 
00000000  66 34 6b 6d 6d 36 70 7c  3d 82 7f 70 82 6e 83 82  |f4kmm6p|=..p.n..|
00000010  44 42 83 44 75 7b 7f 8c  89 0a                    |DB.Du{....|
0000001a

66 - 0 => f
34 - 1 => 3
6b - 2 = 107 - 2 => i
6d - 3 = 109 - 3 => j
6d - 4 = 109 - 4 => i
36 - 5 = 54 - 5 => 1
etc...

we just have to run a simple C++ script to open the file and to substract the index value to get the original value.
after running the script we have this:
f3iji1ju5yuevaus41q1afiuq

and then you have the password for getting flag!