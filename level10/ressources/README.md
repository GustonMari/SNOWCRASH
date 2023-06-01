As the previous levels we can see an executable and a token with no permissions
we copy via scp the executable (level10) and decompil it with Ghidra.

We can see few things, it used socket to connect, and it use the port 6969:
printf("Connecting to %s:6969 .. ",__cp); --> look at level10.c
when you read the different call to printf you can think its a sort of server
for sending a file.

In the main of level10.c, the program checks if you have read access to a specified file using the access() function. If the access check (fd == 0) succeeds, it proceeds to connect to a host and send the contents of the file.

To bypass the file access check, you can try modifying the value of fd variable to make it equal to 0. This way, the program will think that you have read access to the file, allowing you to proceed with opening and reading its contents.

First, in the VM, we open a port 6969 --> nc -lk 6969 (works like a server)
this is on this server that we will retrieve the information of the flag back.

So we are going to scam the program with create a symbolic link with
and empty file over and over and send it to the level10 binary at the address 127.0.0.1 (we use the loopback);

We use two symbolic links are created in an infinite loop. The first command creates a symbolic link from /tmp/flaglevel10 to /tmp/flaggood, and the second command creates a symbolic link from the user's ~/token file to /tmp/flaggood.
By providing /tmp/flaggood as an argument to the program, the intention is to trick the program into accessing or modifying the contents of the symbolic link /tmp/flaggood. Since multiple processes are continuously manipulating this symbolic link through race conditions, the program's behavior can become unpredictable and potentially exploitable.
Race conditions can lead to unexpected consequences and security vulnerabilities. They highlight the importance of proper synchronization and resource management in multi-process or multi-threaded programs to prevent unauthorized access or manipulation of shared resources.
So here we have a unpredictable situatation where the race condition leads to get sometimes the password.

Then we have something like this on our "Server" :
.*( )*.
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
.*( )*.
woupa2yuojeeaaed06riuj63c
.*( )*.
woupa2yuojeeaaed06riuj63c

woupa2yuojeeaaed06riuj63c --> is the flag
