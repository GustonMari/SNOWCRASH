typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned char    dwfenc;
typedef unsigned int    dword;
typedef long long    longlong;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef struct eh_frame_hdr eh_frame_hdr, *Peh_frame_hdr;

struct eh_frame_hdr {
    byte eh_frame_hdr_version; // Exception Handler Frame Header Version
    dwfenc eh_frame_pointer_encoding; // Exception Handler Frame Pointer Encoding
    dwfenc eh_frame_desc_entry_count_encoding; // Encoding of # of Exception Handler FDEs
    dwfenc eh_frame_table_encoding; // Exception Handler Table Encoding
};

typedef struct fde_table_entry fde_table_entry, *Pfde_table_entry;

struct fde_table_entry {
    dword initial_loc; // Initial Location
    dword data_loc; // Data location
};

typedef void _IO_lock_t;

typedef struct _IO_marker _IO_marker, *P_IO_marker;

typedef struct _IO_FILE _IO_FILE, *P_IO_FILE;

typedef long __off_t;

typedef longlong __quad_t;

typedef __quad_t __off64_t;

typedef ulong size_t;

struct _IO_FILE {
    int _flags;
    char * _IO_read_ptr;
    char * _IO_read_end;
    char * _IO_read_base;
    char * _IO_write_base;
    char * _IO_write_ptr;
    char * _IO_write_end;
    char * _IO_buf_base;
    char * _IO_buf_end;
    char * _IO_save_base;
    char * _IO_backup_base;
    char * _IO_save_end;
    struct _IO_marker * _markers;
    struct _IO_FILE * _chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    ushort _cur_column;
    char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t * _lock;
    __off64_t _offset;
    void * __pad1;
    void * __pad2;
    void * __pad3;
    void * __pad4;
    size_t __pad5;
    int _mode;
    char _unused2[15];
};

struct _IO_marker {
    struct _IO_marker * _next;
    struct _IO_FILE * _sbuf;
    int _pos;
};

typedef struct _IO_FILE FILE;

typedef uint __uid_t;

typedef struct evp_pkey_ctx_st evp_pkey_ctx_st, *Pevp_pkey_ctx_st;

struct evp_pkey_ctx_st {
};

typedef struct evp_pkey_ctx_st EVP_PKEY_CTX;

typedef enum __ptrace_request {
    PTRACE_ATTACH=16,
    PTRACE_CONT=7,
    PTRACE_DETACH=17,
    PTRACE_GETEVENTMSG=16897,
    PTRACE_GETFPREGS=14,
    PTRACE_GETFPXREGS=18,
    PTRACE_GETREGS=12,
    PTRACE_GETSIGINFO=16898,
    PTRACE_KILL=8,
    PTRACE_PEEKDATA=2,
    PTRACE_PEEKTEXT=1,
    PTRACE_PEEKUSER=3,
    PTRACE_POKEDATA=5,
    PTRACE_POKETEXT=4,
    PTRACE_POKEUSER=6,
    PTRACE_SETFPREGS=15,
    PTRACE_SETFPXREGS=19,
    PTRACE_SETOPTIONS=16896,
    PTRACE_SETREGS=13,
    PTRACE_SETSIGINFO=16899,
    PTRACE_SINGLESTEP=9,
    PTRACE_SYSCALL=24,
    PTRACE_TRACEME=0
} __ptrace_request;

typedef struct Elf32_Dyn_x86 Elf32_Dyn_x86, *PElf32_Dyn_x86;

typedef enum Elf32_DynTag_x86 {
    DT_AUDIT=1879047932,
    DT_AUXILIARY=2147483645,
    DT_BIND_NOW=24,
    DT_CHECKSUM=1879047672,
    DT_CONFIG=1879047930,
    DT_DEBUG=21,
    DT_DEPAUDIT=1879047931,
    DT_ENCODING=32,
    DT_FEATURE_1=1879047676,
    DT_FILTER=2147483647,
    DT_FINI=13,
    DT_FINI_ARRAY=26,
    DT_FINI_ARRAYSZ=28,
    DT_FLAGS=30,
    DT_FLAGS_1=1879048187,
    DT_GNU_CONFLICT=1879047928,
    DT_GNU_CONFLICTSZ=1879047670,
    DT_GNU_HASH=1879047925,
    DT_GNU_LIBLIST=1879047929,
    DT_GNU_LIBLISTSZ=1879047671,
    DT_GNU_PRELINKED=1879047669,
    DT_HASH=4,
    DT_INIT=12,
    DT_INIT_ARRAY=25,
    DT_INIT_ARRAYSZ=27,
    DT_JMPREL=23,
    DT_MOVEENT=1879047674,
    DT_MOVESZ=1879047675,
    DT_MOVETAB=1879047934,
    DT_NEEDED=1,
    DT_NULL=0,
    DT_PLTGOT=3,
    DT_PLTPAD=1879047933,
    DT_PLTPADSZ=1879047673,
    DT_PLTREL=20,
    DT_PLTRELSZ=2,
    DT_POSFLAG_1=1879047677,
    DT_PREINIT_ARRAYSZ=33,
    DT_REL=17,
    DT_RELA=7,
    DT_RELACOUNT=1879048185,
    DT_RELAENT=9,
    DT_RELASZ=8,
    DT_RELCOUNT=1879048186,
    DT_RELENT=19,
    DT_RELSZ=18,
    DT_RPATH=15,
    DT_RUNPATH=29,
    DT_SONAME=14,
    DT_STRSZ=10,
    DT_STRTAB=5,
    DT_SYMBOLIC=16,
    DT_SYMENT=11,
    DT_SYMINENT=1879047679,
    DT_SYMINFO=1879047935,
    DT_SYMINSZ=1879047678,
    DT_SYMTAB=6,
    DT_TEXTREL=22,
    DT_TLSDESC_GOT=1879047927,
    DT_TLSDESC_PLT=1879047926,
    DT_VERDEF=1879048188,
    DT_VERDEFNUM=1879048189,
    DT_VERNEED=1879048190,
    DT_VERNEEDNUM=1879048191,
    DT_VERSYM=1879048176
} Elf32_DynTag_x86;

struct Elf32_Dyn_x86 {
    enum Elf32_DynTag_x86 d_tag;
    dword d_val;
};

typedef struct Elf32_Sym Elf32_Sym, *PElf32_Sym;

struct Elf32_Sym {
    dword st_name;
    dword st_value;
    dword st_size;
    byte st_info;
    byte st_other;
    word st_shndx;
};

typedef struct Elf32_Shdr Elf32_Shdr, *PElf32_Shdr;

typedef enum Elf_SectionHeaderType_x86 {
    SHT_CHECKSUM=1879048184,
    SHT_DYNAMIC=6,
    SHT_DYNSYM=11,
    SHT_FINI_ARRAY=15,
    SHT_GNU_ATTRIBUTES=1879048181,
    SHT_GNU_HASH=1879048182,
    SHT_GNU_LIBLIST=1879048183,
    SHT_GNU_verdef=1879048189,
    SHT_GNU_verneed=1879048190,
    SHT_GNU_versym=1879048191,
    SHT_GROUP=17,
    SHT_HASH=5,
    SHT_INIT_ARRAY=14,
    SHT_NOBITS=8,
    SHT_NOTE=7,
    SHT_NULL=0,
    SHT_PREINIT_ARRAY=16,
    SHT_PROGBITS=1,
    SHT_REL=9,
    SHT_RELA=4,
    SHT_SHLIB=10,
    SHT_STRTAB=3,
    SHT_SUNW_COMDAT=1879048187,
    SHT_SUNW_move=1879048186,
    SHT_SUNW_syminfo=1879048188,
    SHT_SYMTAB=2,
    SHT_SYMTAB_SHNDX=18
} Elf_SectionHeaderType_x86;

struct Elf32_Shdr {
    dword sh_name;
    enum Elf_SectionHeaderType_x86 sh_type;
    dword sh_flags;
    dword sh_addr;
    dword sh_offset;
    dword sh_size;
    dword sh_link;
    dword sh_info;
    dword sh_addralign;
    dword sh_entsize;
};

typedef struct Elf32_Phdr Elf32_Phdr, *PElf32_Phdr;

typedef enum Elf_ProgramHeaderType_x86 {
    PT_DYNAMIC=2,
    PT_GNU_EH_FRAME=1685382480,
    PT_GNU_RELRO=1685382482,
    PT_GNU_STACK=1685382481,
    PT_INTERP=3,
    PT_LOAD=1,
    PT_NOTE=4,
    PT_NULL=0,
    PT_PHDR=6,
    PT_SHLIB=5,
    PT_TLS=7
} Elf_ProgramHeaderType_x86;

struct Elf32_Phdr {
    enum Elf_ProgramHeaderType_x86 p_type;
    dword p_offset;
    dword p_vaddr;
    dword p_paddr;
    dword p_filesz;
    dword p_memsz;
    dword p_flags;
    dword p_align;
};

typedef struct Elf32_Rel Elf32_Rel, *PElf32_Rel;

struct Elf32_Rel {
    dword r_offset; // location to apply the relocation action
    dword r_info; // the symbol table index and the type of relocation
};

typedef struct Elf32_Ehdr Elf32_Ehdr, *PElf32_Ehdr;

struct Elf32_Ehdr {
    byte e_ident_magic_num;
    char e_ident_magic_str[3];
    byte e_ident_class;
    byte e_ident_data;
    byte e_ident_version;
    byte e_ident_pad[9];
    word e_type;
    word e_machine;
    dword e_version;
    dword e_entry;
    dword e_phoff;
    dword e_shoff;
    dword e_flags;
    word e_ehsize;
    word e_phentsize;
    word e_phnum;
    word e_shentsize;
    word e_shnum;
    word e_shstrndx;
};




int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  __gmon_start__();
  frame_dummy();
  iVar1 = __do_global_ctors_aux();
  return iVar1;
}



void FUN_08048480(void)

{
                    // WARNING: Treating indirect jump as call
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

char * strdup(char *__s)

{
  char *pcVar1;
  
  pcVar1 = strdup(__s);
  return pcVar1;
}



void __stack_chk_fail(void)

{
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Unknown calling convention yet parameter storage is locked

__uid_t getuid(void)

{
  __uid_t _Var1;
  
  _Var1 = getuid();
  return _Var1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = fwrite(__ptr,__size,__n,__s);
  return sVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

char * getenv(char *__name)

{
  char *pcVar1;
  
  pcVar1 = getenv(__name);
  return pcVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



void __gmon_start__(void)

{
  __gmon_start__();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int open(char *__file,int __oflag,...)

{
  int iVar1;
  
  iVar1 = open(__file,__oflag);
  return iVar1;
}



void __libc_start_main(void)

{
  __libc_start_main();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int fputc(int __c,FILE *__stream)

{
  int iVar1;
  
  iVar1 = fputc(__c,__stream);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int fputs(char *__s,FILE *__stream)

{
  int iVar1;
  
  iVar1 = fputs(__s,__stream);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

long ptrace(__ptrace_request __request,...)

{
  long lVar1;
  
  lVar1 = ptrace(__request);
  return lVar1;
}



void _start(void)

{
  __libc_start_main(main);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x080485aa)
// WARNING: Removing unreachable block (ram,0x080485b0)

void __do_global_dtors_aux(void)

{
  if (completed_6159 == 0) {
    completed_6159 = 1;
  }
  return;
}



// WARNING: Removing unreachable block (ram,0x080485f8)

void frame_dummy(void)

{
  return;
}



char * ft_des(char *param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  byte bVar5;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  bVar5 = 0;
  pcVar2 = strdup(param_1);
  local_1c = 0;
  local_20 = 0;
  do {
    uVar3 = 0xffffffff;
    pcVar4 = pcVar2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + (uint)bVar5 * -2 + 1;
    } while (cVar1 != 0);
    if (~uVar3 - 1 <= local_20) {
      return pcVar2;
    }
    if (local_1c == 6) {
      local_1c = 0;
    }
    if ((local_20 & 1) == 0) {
      if ((local_20 & 1) == 0) {
        local_14 = 0;
        while (local_14 < (int)"0123456"[local_1c]) {
          pcVar2[local_20] = pcVar2[local_20] + -1;
          if (pcVar2[local_20] == 0x1f) {
            pcVar2[local_20] = '~';
          }
          local_14 = local_14 + 1;
        }
      }
    }
    else {
      local_18 = 0;
      while (local_18 < (int)"0123456"[local_1c]) {
        pcVar2[local_20] = pcVar2[local_20] + 1;
        if (pcVar2[local_20] == 0x7f) {
          pcVar2[local_20] = ' ';
        }
        local_18 = local_18 + 1;
      }
    }
    local_20 = local_20 + 1;
    local_1c = local_1c + 1;
  } while( true );
}



undefined4 syscall_open(void)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = (code *)swi(0x80);
  uVar2 = (*pcVar1)();
  return uVar2;
}



uint syscall_gets(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  uint local_14;
  
  local_14 = 0;
  do {
    if (param_2 - 1U <= local_14) {
LAB_080487a9:
      *(undefined *)(local_14 + param_1) = 0;
      return local_14;
    }
    pcVar1 = (code *)swi(0x80);
    iVar2 = (*pcVar1)();
    if (iVar2 != 1) goto LAB_080487a9;
    if (*(char *)(local_14 + param_1) == '\n') {
      local_14 = local_14 + 1;
      goto LAB_080487a9;
    }
    local_14 = local_14 + 1;
  } while( true );
}



char * afterSubstr(char *param_1,int param_2)

{
  bool bVar1;
  int local_10;
  char *local_8;
  
  bVar1 = false;
  local_8 = param_1;
  while (*local_8 != 0) {
    bVar1 = true;
    local_10 = 0;
    while ((bVar1 && (*(char *)(local_10 + param_2) != 0))) {
      if (*(char *)(local_10 + param_2) != local_8[local_10]) {
        bVar1 = false;
      }
      local_10 = local_10 + 1;
    }
    if (bVar1) break;
    local_8 = local_8 + 1;
  }
  if (bVar1) {
    local_8 = local_8 + local_10;
  }
  else {
    local_8 = (char *)0x0;
  }
  return local_8;
}



undefined4 isLib(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  char *pcVar2;
  undefined4 uVar3;
  int local_10;
  char *local_8;
  
  pcVar2 = (char *)afterSubstr(param_1,param_2);
  if (pcVar2 == (char *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*pcVar2 == '-') {
      bVar1 = false;
      while ((local_8 = pcVar2 + 1, '/' < *local_8 && (*local_8 < ':'))) {
        bVar1 = true;
        pcVar2 = local_8;
      }
      if ((bVar1) && (*local_8 == '.')) {
        bVar1 = false;
        local_8 = pcVar2 + 2;
        while (('/' < *local_8 && (*local_8 < ':'))) {
          bVar1 = true;
          local_8 = local_8 + 1;
        }
        if (bVar1) {
          local_10 = 0;
          while (end_3187[local_10] != 0) {
            if (end_3187[local_10] != local_8[local_10]) {
              return 0;
            }
            local_10 = local_10 + 1;
          }
          uVar3 = 1;
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}



undefined4 main(void)

{
  bool bVar1;
  FILE *__stream;
  long lVar2;
  undefined4 uVar3;
  char *__s;
  int iVar4;
  __uid_t _Var5;
  int iVar6;
  int in_GS_OFFSET;
  undefined local_114 [256];
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  bVar1 = false;
  lVar2 = ptrace(PTRACE_TRACEME,0,1,0);
  if (lVar2 < 0) {
    puts("You should not reverse this");
    uVar3 = 1;
  }
  else {
    __s = getenv("LD_PRELOAD");
    if (__s == (char *)0x0) {
      iVar4 = open("/etc/ld.so.preload",0);
      if (iVar4 < 1) {
        iVar4 = syscall_open("/proc/self/maps",0);
        if (iVar4 == -1) {
          fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n",1,0x46,
                 stderr);
          uVar3 = 1;
        }
        else {
          do {
            do {
              while( true ) {
                iVar6 = syscall_gets(local_114,0x100,iVar4);
                if (iVar6 == 0) goto LAB_08048ead;
                iVar6 = isLib(local_114,&DAT_08049063);
                if (iVar6 == 0) break;
                bVar1 = true;
              }
            } while (!bVar1);
            iVar6 = isLib(local_114,&DAT_08049068);
            if (iVar6 != 0) {
              fwrite("Check flag.Here is your token : ",1,0x20,stdout);
              _Var5 = getuid();
              __stream = stdout;
              if (_Var5 == 0xbbe) {
                __s = (char *)ft_des("H8B8h_20B4J43><8>\\ED<;j@3");
                fputs(__s,__stream);
              }
              else {
                if (_Var5 < 0xbbf) {
                  if (_Var5 == 0xbba) {
                    __s = (char *)ft_des("<>B16\\AD<C6,G_<1>^7ci>l4B");
                    fputs(__s,__stream);
                  }
                  else {
                    if (_Var5 < 0xbbb) {
                      if (_Var5 == 3000) {
                        __s = (char *)ft_des("I`fA>_88eEd:=`85h0D8HE>,D");
                        fputs(__s,__stream);
                      }
                      else {
                        if (_Var5 < 0xbb9) {
                          if (_Var5 == 0) {
                            fwrite("You are root are you that dumb ?\n",1,0x21,stdout);
                          }
                          else {
LAB_08048e06:
                            fwrite("\nNope there is no token here for you sorry. Try again :)",1,
                                   0x38,stdout);
                          }
                        }
                        else {
                          __s = (char *)ft_des("7`4Ci4=^d=J,?>i;6,7d416,7");
                          fputs(__s,__stream);
                        }
                      }
                    }
                    else {
                      if (_Var5 == 0xbbc) {
                        __s = (char *)ft_des("?4d@:,C>8C60G>8:h:Gb4?l,A");
                        fputs(__s,__stream);
                      }
                      else {
                        if (_Var5 < 0xbbd) {
                          __s = (char *)ft_des("B8b:6,3fj7:,;bh>D@>8i:6@D");
                          fputs(__s,__stream);
                        }
                        else {
                          __s = (char *)ft_des("G8H.6,=4k5J0<cd/D@>>B:>:4");
                          fputs(__s,__stream);
                        }
                      }
                    }
                  }
                }
                else {
                  if (_Var5 == 0xbc2) {
                    __s = (char *)ft_des("74H9D^3ed7k05445J0E4e;Da4");
                    fputs(__s,__stream);
                  }
                  else {
                    if (_Var5 < 0xbc3) {
                      if (_Var5 == 0xbc0) {
                        __s = (char *)ft_des("bci`mC{)jxkn<\"uD~6%g7FK`7");
                        fputs(__s,__stream);
                      }
                      else {
                        if (_Var5 < 0xbc1) {
                          __s = (char *)ft_des("78H:J4<4<9i_I4k0J^5>B1j`9");
                          fputs(__s,__stream);
                        }
                        else {
                          __s = (char *)ft_des("Dc6m~;}f8Cj#xFkel;#&ycfbK");
                          fputs(__s,__stream);
                        }
                      }
                    }
                    else {
                      if (_Var5 == 0xbc4) {
                        __s = (char *)ft_des("8_Dw\"4#?+3i]q&;p6 gtw88EC");
                        fputs(__s,__stream);
                      }
                      else {
                        if (_Var5 < 0xbc4) {
                          __s = (char *)ft_des("70hCi,E44Df[A4B/J@3f<=:`D");
                          fputs(__s,__stream);
                        }
                        else {
                          if (_Var5 == 0xbc5) {
                            __s = (char *)ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
                            fputs(__s,__stream);
                          }
                          else {
                            if (_Var5 != 0xbc6) goto LAB_08048e06;
                            __s = (char *)ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
                            fputs(__s,__stream);
                          }
                        }
                      }
                    }
                  }
                }
              }
              fputc(10,stdout);
              goto LAB_08048ead;
            }
            iVar6 = afterSubstr(local_114,"00000000 00:00 0");
          } while (iVar6 != 0);
          fwrite("LD_PRELOAD detected through memory maps exit ..\n",1,0x30,stderr);
LAB_08048ead:
          uVar3 = 0;
        }
      }
      else {
        fwrite("Injection Linked lib detected exit..\n",1,0x25,stderr);
        uVar3 = 1;
      }
    }
    else {
      fwrite("Injection Linked lib detected exit..\n",1,0x25,stderr);
      uVar3 = 1;
    }
  }
  if (local_14 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    // WARNING: Subroutine does not return
  __stack_chk_fail();
}



// WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx
// WARNING: Removing unreachable block (ram,0x08048f00)
// WARNING: Removing unreachable block (ram,0x08048f08)

void __libc_csu_init(void)

{
  EVP_PKEY_CTX *local_2c;
  
  _init(local_2c);
  return;
}



void __libc_csu_fini(void)

{
  return;
}



// WARNING: This is an inlined function

void __i686_get_pc_thunk_bx(void)

{
  return;
}



void __do_global_ctors_aux(void)

{
  code *pcVar1;
  code **ppcVar2;
  
  if (__CTOR_LIST__ != (code *)0xffffffff) {
    ppcVar2 = (code **)&__CTOR_LIST__;
    pcVar1 = __CTOR_LIST__;
    do {
      ppcVar2 = ppcVar2 + -1;
      (*pcVar1)();
      pcVar1 = *ppcVar2;
    } while (pcVar1 != (code *)0xffffffff);
  }
  return;
}



void _fini(void)

{
  __do_global_dtors_aux();
  return;
}


