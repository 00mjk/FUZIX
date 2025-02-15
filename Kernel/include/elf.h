/*-
 * Copyright (c) 1995, 1996 Erik Theisen.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * This is the ELF ABI header file
 * formerly known as "elf_abi.h".
 */

#ifndef _SYS_ELF_H_
#define _SYS_ELF_H_

typedef uint8_t	Elf_Byte;

typedef uint32_t	Elf32_Addr;	/* Unsigned program address */
typedef uint32_t	Elf32_Off;	/* Unsigned file offset */
typedef int32_t		Elf32_Sword;	/* Signed large integer */
typedef uint32_t	Elf32_Word;	/* Unsigned large integer */
typedef uint16_t	Elf32_Half;	/* Unsigned medium integer */

/* e_ident[] identification indexes */
#define EI_MAG0		0		/* file ID */
#define EI_MAG1		1		/* file ID */
#define EI_MAG2		2		/* file ID */
#define EI_MAG3		3		/* file ID */
#define EI_CLASS	4		/* file class */
#define EI_DATA		5		/* data encoding */
#define EI_VERSION	6		/* ELF header version */
#define EI_OSABI	7	/* Operating system / ABI identification */
#define EI_ABIVERSION	8	/* ABI version */
#define OLD_EI_BRAND	8	/* Start of architecture identification. */
#define EI_PAD		9	/* Start of padding (per SVR4 ABI). */
#define EI_NIDENT	16		/* Size of e_ident[] */

/* e_ident[] magic number */
#define	ELFMAG0		0x7f		/* e_ident[EI_MAG0] */
#define	ELFMAG1		'E'		/* e_ident[EI_MAG1] */
#define	ELFMAG2		'L'		/* e_ident[EI_MAG2] */
#define	ELFMAG3		'F'		/* e_ident[EI_MAG3] */
#define	ELFMAG		"\177ELF"	/* magic */
#define	SELFMAG		4		/* size of magic */

/* e_ident[] file class */
#define	ELFCLASSNONE	0		/* invalid */
#define	ELFCLASS32	1		/* 32-bit objs */
#define	ELFCLASS64	2		/* 64-bit objs */
#define	ELFCLASSNUM	3		/* number of classes */

/* e_ident[] data encoding */
#define ELFDATANONE	0		/* invalid */
#define ELFDATA2LSB	1		/* Little-Endian */
#define ELFDATA2MSB	2		/* Big-Endian */
#define ELFDATANUM	3		/* number of data encode defines */

/* e_ident[] OS ABI */
#define ELFOSABI_SYSV		0	/* UNIX System V ABI */
#define ELFOSABI_NONE		ELFOSABI_SYSV	/* symbol used in old spec */
#define ELFOSABI_HPUX		1	/* HP-UX operating system */
#define ELFOSABI_NETBSD		2	/* NetBSD */
#define ELFOSABI_LINUX		3	/* GNU/Linux */
#define ELFOSABI_HURD		4	/* GNU/Hurd */
#define ELFOSABI_86OPEN		5	/* 86Open common IA32 ABI */
#define ELFOSABI_SOLARIS	6	/* Solaris */
#define ELFOSABI_MONTEREY	7	/* Monterey */
#define ELFOSABI_IRIX		8	/* IRIX */
#define ELFOSABI_FREEBSD	9	/* FreeBSD */
#define ELFOSABI_TRU64		10	/* TRU64 UNIX */
#define ELFOSABI_MODESTO	11	/* Novell Modesto */
#define ELFOSABI_OPENBSD	12	/* OpenBSD */
#define ELFOSABI_ARM		97	/* ARM */
#define ELFOSABI_STANDALONE	255	/* Standalone (embedded) application */

/* e_ident */
#define IS_ELF(ehdr) ((ehdr).e_ident[EI_MAG0] == ELFMAG0 && \
                      (ehdr).e_ident[EI_MAG1] == ELFMAG1 && \
                      (ehdr).e_ident[EI_MAG2] == ELFMAG2 && \
                      (ehdr).e_ident[EI_MAG3] == ELFMAG3)

/* ELF Header */
typedef struct elfhdr{
	unsigned char	e_ident[EI_NIDENT]; /* ELF Identification */
	Elf32_Half	e_type;		/* object file type */
	Elf32_Half	e_machine;	/* machine */
	Elf32_Word	e_version;	/* object file version */
	Elf32_Addr	e_entry;	/* virtual entry point */
	Elf32_Off	e_phoff;	/* program header table offset */
	Elf32_Off	e_shoff;	/* section header table offset */
	Elf32_Word	e_flags;	/* processor-specific flags */
	Elf32_Half	e_ehsize;	/* ELF header size */
	Elf32_Half	e_phentsize;	/* program header entry size */
	Elf32_Half	e_phnum;	/* number of program header entries */
	Elf32_Half	e_shentsize;	/* section header entry size */
	Elf32_Half	e_shnum;	/* number of section header entries */
	Elf32_Half	e_shstrndx;	/* section header table's "section
					   header string table" entry offset */
} Elf32_Ehdr;

/* e_type */
#define ET_NONE		0		/* No file type */
#define ET_REL		1		/* relocatable file */
#define ET_EXEC		2		/* executable file */
#define ET_DYN		3		/* shared object file */
#define ET_CORE		4		/* core file */
#define ET_NUM		5		/* number of types */
#define ET_LOPROC	0xff00		/* reserved range for processor */
#define ET_HIPROC	0xffff		/*  specific e_type */

/* e_machine */
#define EM_NONE		0		/* No Machine */
#define EM_M32		1		/* AT&T WE 32100 */
#define EM_SPARC	2		/* SPARC */
#define EM_386		3		/* Intel 80386 */
#define EM_68K		4		/* Motorola 68000 */
#define EM_88K		5		/* Motorola 88000 */
#define EM_486		6		/* Intel 80486 - unused? */
#define EM_860		7		/* Intel 80860 */
#define EM_MIPS		8		/* MIPS R3000 Big-Endian only */
/*
 * Don't know if EM_MIPS_RS4_BE,
 * EM_SPARC64, EM_PARISC,
 * or EM_PPC are ABI compliant
 */
#define EM_MIPS_RS4_BE	10		/* MIPS R4000 Big-Endian */
#define EM_SPARC64	11		/* SPARC v9 64-bit unoffical */
#define EM_PARISC	15		/* HPPA */
#define EM_SPARC32PLUS	18		/* Enhanced instruction set SPARC */
#define EM_PPC		20		/* PowerPC */
#define EM_ARM		40
#define EM_ALPHA	41		/* DEC ALPHA */
#define EM_SPARCV9	43		/* SPARC version 9 */
#define EM_ALPHA_EXP	0x9026		/* DEC ALPHA */
#define EM_VAX		75		/* DEC VAX */
#define EM_NUM		15		/* number of machine types */

/* Version */
#define EV_NONE		0		/* Invalid */
#define EV_CURRENT	1		/* Current */
#define EV_NUM		2		/* number of versions */

/* Section Header */
typedef struct {
	Elf32_Word	sh_name;	/* name - index into section header
					   string table section */
	Elf32_Word	sh_type;	/* type */
	Elf32_Word	sh_flags;	/* flags */
	Elf32_Addr	sh_addr;	/* address */
	Elf32_Off	sh_offset;	/* file offset */
	Elf32_Word	sh_size;	/* section size */
	Elf32_Word	sh_link;	/* section header table index link */
	Elf32_Word	sh_info;	/* extra information */
	Elf32_Word	sh_addralign;	/* address alignment */
	Elf32_Word	sh_entsize;	/* section entry size */
} Elf32_Shdr;

/* Special Section Indexes */
#define SHN_UNDEF	0		/* undefined */
#define SHN_LORESERVE	0xff00		/* lower bounds of reserved indexes */
#define SHN_LOPROC	0xff00		/* reserved range for processor */
#define SHN_HIPROC	0xff1f		/*   specific section indexes */
#define SHN_ABS		0xfff1		/* absolute value */
#define SHN_COMMON	0xfff2		/* common symbol */
#define SHN_HIRESERVE	0xffff		/* upper bounds of reserved indexes */

/* sh_type */
#define SHT_NULL	0		/* inactive */
#define SHT_PROGBITS	1		/* program defined information */
#define SHT_SYMTAB	2		/* symbol table section */
#define SHT_STRTAB	3		/* string table section */
#define SHT_RELA	4		/* relocation section with addends*/
#define SHT_HASH	5		/* symbol hash table section */
#define SHT_DYNAMIC	6		/* dynamic section */
#define SHT_NOTE	7		/* note section */
#define SHT_NOBITS	8		/* no space section */
#define SHT_REL		9		/* relation section without addends */
#define SHT_SHLIB	10		/* reserved - purpose unknown */
#define SHT_DYNSYM	11		/* dynamic symbol table section */
#define SHT_NUM		12		/* number of section types */
#define SHT_LOPROC	0x70000000	/* reserved range for processor */
#define SHT_HIPROC	0x7fffffff	/*  specific section header types */
#define SHT_LOUSER	0x80000000	/* reserved range for application */
#define SHT_HIUSER	0xffffffff	/*  specific indexes */

/* Section names */
#define ELF_BSS         ".bss"		/* uninitialized data */
#define ELF_DATA        ".data"		/* initialized data */
#define ELF_DEBUG       ".debug"	/* debug */
#define ELF_DYNAMIC     ".dynamic"	/* dynamic linking information */
#define ELF_DYNSTR      ".dynstr"	/* dynamic string table */
#define ELF_DYNSYM      ".dynsym"	/* dynamic symbol table */
#define ELF_FINI        ".fini"		/* termination code */
#define ELF_GOT         ".got"		/* global offset table */
#define ELF_HASH        ".hash"		/* symbol hash table */
#define ELF_INIT        ".init"		/* initialization code */
#define ELF_REL_DATA    ".rel.data"	/* relocation data */
#define ELF_REL_FINI    ".rel.fini"	/* relocation termination code */
#define ELF_REL_INIT    ".rel.init"	/* relocation initialization code */
#define ELF_REL_DYN     ".rel.dyn"	/* relocaltion dynamic link info */
#define ELF_REL_RODATA  ".rel.rodata"	/* relocation read-only data */
#define ELF_REL_TEXT    ".rel.text"	/* relocation code */
#define ELF_RODATA      ".rodata"	/* read-only data */
#define ELF_SHSTRTAB    ".shstrtab"	/* section header string table */
#define ELF_STRTAB      ".strtab"	/* string table */
#define ELF_SYMTAB      ".symtab"	/* symbol table */
#define ELF_TEXT        ".text"		/* code */


/* Section Attribute Flags - sh_flags */
#define SHF_WRITE	0x1		/* Writable */
#define SHF_ALLOC	0x2		/* occupies memory */
#define SHF_EXECINSTR	0x4		/* executable */
#define SHF_MASKPROC	0xf0000000	/* reserved bits for processor */
					/*  specific section attributes */

/* Symbol Table Entry */
typedef struct elf32_sym {
	Elf32_Word	st_name;	/* name - index into string table */
	Elf32_Addr	st_value;	/* symbol value */
	Elf32_Word	st_size;	/* symbol size */
	unsigned char	st_info;	/* type and binding */
	unsigned char	st_other;	/* 0 - no defined meaning */
	Elf32_Half	st_shndx;	/* section header index */
} Elf32_Sym;

/* Symbol table index */
#define STN_UNDEF	0		/* undefined */

/* Extract symbol info - st_info */
#define ELF32_ST_BIND(x)	((x) >> 4)
#define ELF32_ST_TYPE(x)	(((unsigned int) x) & 0xf)
#define ELF32_ST_INFO(b,t)	(((b) << 4) + ((t) & 0xf))

/* Symbol Binding - ELF32_ST_BIND - st_info */
#define STB_LOCAL	0		/* Local symbol */
#define STB_GLOBAL	1		/* Global symbol */
#define STB_WEAK	2		/* like global - lower precedence */
#define STB_NUM		3		/* number of symbol bindings */
#define STB_LOPROC	13		/* reserved range for processor */
#define STB_HIPROC	15		/*  specific symbol bindings */

/* Symbol type - ELF32_ST_TYPE - st_info */
#define STT_NOTYPE	0		/* not specified */
#define STT_OBJECT	1		/* data object */
#define STT_FUNC	2		/* function */
#define STT_SECTION	3		/* section */
#define STT_FILE	4		/* file */
#define STT_NUM		5		/* number of symbol types */
#define STT_LOPROC	13		/* reserved range for processor */
#define STT_HIPROC	15		/*  specific symbol types */

/* Relocation entry with implicit addend */
typedef struct
{
	Elf32_Addr	r_offset;	/* offset of relocation */
	Elf32_Word	r_info;		/* symbol table index and type */
} Elf32_Rel;

/* Relocation entry with explicit addend */
typedef struct
{
	Elf32_Addr	r_offset;	/* offset of relocation */
	Elf32_Word	r_info;		/* symbol table index and type */
	Elf32_Sword	r_addend;
} Elf32_Rela;

/* Extract relocation info - r_info */
#define ELF32_R_SYM(i)		((i) >> 8)
#define ELF32_R_TYPE(i)		((unsigned char) (i))
#define ELF32_R_INFO(s,t) 	(((s) << 8) + (unsigned char)(t))

/* Program Header */
typedef struct {
	Elf32_Word	p_type;		/* segment type */
	Elf32_Off	p_offset;	/* segment offset */
	Elf32_Addr	p_vaddr;	/* virtual address of segment */
	Elf32_Addr	p_paddr;	/* physical address - ignored? */
	Elf32_Word	p_filesz;	/* number of bytes in file for seg. */
	Elf32_Word	p_memsz;	/* number of bytes in mem. for seg. */
	Elf32_Word	p_flags;	/* flags */
	Elf32_Word	p_align;	/* memory alignment */
} Elf32_Phdr;

/* Segment types - p_type */
#define PT_NULL		0		/* unused */
#define PT_LOAD		1		/* loadable segment */
#define PT_DYNAMIC	2		/* dynamic linking section */
#define PT_INTERP	3		/* the RTLD */
#define PT_NOTE		4		/* auxiliary information */
#define PT_SHLIB	5		/* reserved - purpose undefined */
#define PT_PHDR		6		/* program header */
#define PT_NUM		7		/* Number of segment types */
#define PT_LOOS     0x60000000  /* reserved range for operating system */
#define PT_HIOS     0x6fffffff  /*  specific segment types */
#define PT_LOPROC	0x70000000	/* reserved range for processor */
#define PT_HIPROC	0x7fffffff	/*  specific segment types */

/* Segment flags - p_flags */
#define PF_X		0x1		/* Executable */
#define PF_W		0x2		/* Writable */
#define PF_R		0x4		/* Readable */
#define PF_MASKPROC	0xf0000000	/* reserved bits for processor */
					/*  specific segment flags */

/* Dynamic structure */
typedef struct {
	Elf32_Sword	d_tag;		/* controls meaning of d_val */
	union {
		Elf32_Word	d_val;	/* Multiple meanings - see d_tag */
		Elf32_Addr	d_ptr;	/* program virtual address */
	} d_un;
} Elf32_Dyn;

/* Dynamic Array Tags - d_tag */
#define DT_NULL		0		/* marks end of _DYNAMIC array */
#define DT_NEEDED	1		/* string table offset of needed lib */
#define DT_PLTRELSZ	2		/* size of relocation entries in PLT */
#define DT_PLTGOT	3		/* address PLT/GOT */
#define DT_HASH		4		/* address of symbol hash table */
#define DT_STRTAB	5		/* address of string table */
#define DT_SYMTAB	6		/* address of symbol table */
#define DT_RELA		7		/* address of relocation table */
#define DT_RELASZ	8		/* size of relocation table */
#define DT_RELAENT	9		/* size of relocation entry */
#define DT_STRSZ	10		/* size of string table */
#define DT_SYMENT	11		/* size of symbol table entry */
#define DT_INIT		12		/* address of initialization func. */
#define DT_FINI		13		/* address of termination function */
#define DT_SONAME	14		/* string table offset of shared obj */
#define DT_RPATH	15		/* string table offset of library
					   search path */
#define DT_SYMBOLIC	16		/* start sym search in shared obj. */
#define DT_REL		17		/* address of rel. tbl. w addends */
#define DT_RELSZ	18		/* size of DT_REL relocation table */
#define DT_RELENT	19		/* size of DT_REL relocation entry */
#define DT_PLTREL	20		/* PLT referenced relocation entry */
#define DT_DEBUG	21		/* bugger */
#define DT_TEXTREL	22		/* Allow rel. mod. to unwritable seg */
#define DT_JMPREL	23		/* add. of PLT's relocation entries */
#define DT_BIND_NOW	24		/* Bind now regardless of env setting */
#define DT_NUM		25		/* Number used. */
#define DT_RELCOUNT 0x6ffffffa  /* GNU extension: number of relocations */
#define DT_LOPROC	0x70000000	/* reserved range for processor */
#define DT_HIPROC	0x7fffffff	/*  specific dynamic array tags */

/* Standard ELF hashing function */
unsigned int elf_hash(const unsigned char *name);

/*
 * Note Definitions
 */
typedef struct {
	Elf32_Word namesz;
	Elf32_Word descsz;
	Elf32_Word type;
} Elf32_Note;

/*
 * XXX - these _KERNEL items aren't part of the ABI!
 */
#if defined(_KERNEL) || defined(_DYN_LOADER)

#define ELF32_NO_ADDR	((u_long) ~0)	/* Indicates addr. not yet filled in */
#define ELF_AUX_ENTRIES	8		/* Size of aux array passed to loader */

typedef struct {
	Elf32_Sword	au_id;				/* 32-bit id */
	Elf32_Word	au_v;				/* 32-bit value */
} Aux32Info;

enum AuxID {
	AUX_null = 0,
	AUX_ignore = 1,
	AUX_execfd = 2,
	AUX_phdr = 3,			/* &phdr[0] */
	AUX_phent = 4,			/* sizeof(phdr[0]) */
	AUX_phnum = 5,			/* # phdr entries */
	AUX_pagesz = 6,			/* PAGESIZE */
	AUX_base = 7,			/* ld.so base addr */
	AUX_flags = 8,			/* processor flags */
	AUX_entry = 9,			/* a.out entry */
	AUX_sun_uid = 2000,		/* euid */
	AUX_sun_ruid = 2001,		/* ruid */
	AUX_sun_gid = 2002,		/* egid */
	AUX_sun_rgid = 2003		/* rgid */
};

struct elf_args {
        u_long  arg_entry;		/* program entry point */
        u_long  arg_interp;		/* Interpreter load address */
        u_long  arg_phaddr;		/* program header address */
        u_long  arg_phentsize;		/* Size of program header */
        u_long  arg_phnum;		/* Number of program headers */
        u_long  arg_os;			/* OS tag */
};

#endif

#if !defined(ELFSIZE) && defined(ARCH_ELFSIZE)
#define ELFSIZE ARCH_ELFSIZE
#endif

#if defined(ELFSIZE)
#define CONCAT(x,y)	__CONCAT(x,y)
#define ELFNAME(x)	CONCAT(elf,CONCAT(ELFSIZE,CONCAT(_,x)))
#define ELFNAME2(x,y)	CONCAT(x,CONCAT(_elf,CONCAT(ELFSIZE,CONCAT(_,y))))
#define ELFNAMEEND(x)	CONCAT(x,CONCAT(_elf,ELFSIZE))
#define ELFDEFNNAME(x)	CONCAT(ELF,CONCAT(ELFSIZE,CONCAT(_,x)))
#endif

#define Elf_Ehdr	Elf32_Ehdr
#define Elf_Phdr	Elf32_Phdr
#define Elf_Shdr	Elf32_Shdr
#define Elf_Sym		Elf32_Sym
#define Elf_Rel		Elf32_Rel
#define Elf_RelA	Elf32_Rela
#define Elf_Dyn		Elf32_Dyn
#define Elf_Word	Elf32_Word
#define Elf_Sword	Elf32_Sword
#define Elf_Addr	Elf32_Addr
#define Elf_Off		Elf32_Off
#define Elf_Nhdr	Elf32_Nhdr
#define Elf_Note	Elf32_Note

#define ELF_R_SYM	ELF32_R_SYM
#define ELF_R_TYPE	ELF32_R_TYPE
#define ELF_R_INFO	ELF32_R_INFO
#define ELFCLASS	ELFCLASS32

#define ELF_ST_BIND	ELF32_ST_BIND
#define ELF_ST_TYPE	ELF32_ST_TYPE
#define ELF_ST_INFO	ELF32_ST_INFO

#define AuxInfo		Aux32Info

#define ELF_TARG_VER	1	/* The ver for which this code is intended */

#define EM_68K	4
#define EM_ARM	40

/* ARM relocations */

#define R_ARM_NONE       0
#define R_ARM_PC24       1
#define R_ARM_ABS32      2
#define R_ARM_THM_CALL   10
#define R_ARM_RELATIVE   23
#define R_ARM_PLT32      27
#define R_ARM_CALL       28
#define R_ARM_JUMP24     29
#define R_ARM_THM_JUMP11 102

#define R_68K_32	1
#define R_68K_16	2
#define R_68K_8		3
#define R_68K_PC32	4
#define R_68K_PC16	5
#define R_68K_PC8	6
#define R_68K_GOT32	7
#define R_68K_GOT16	8
#define R_68K_GOT8	9
#define R_68K_GOT32O	10
#define R_68K_GOT16O	11
#define R_68K_GOT8O	12

extern int platform_relocate_rel(Elf32_Rel* rel, uaddr_t section_base);

#endif /* _SYS_ELF_H_ */
