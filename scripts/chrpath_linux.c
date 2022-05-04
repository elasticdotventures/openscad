/***************************************************************************
 *                                                                         *
 * This is a pre-configured single file version of chrpath for linux.      *
 * It is used in the binary installer for OpenSCAD on Linux.               *
 *                                                                         *
 * This file has been created by running                                   *
 *   cat *.h *.c | sed 's, *# *include *",//&,' > ../chrpath_linux.c       *
 * in the configured chrpath-0.13 source directory (as found in the debian *
 * package repository as the original download site seams to be down).     *
 *                                                                         *
 * chrpath is licensed under the terms of GPLv2:                           *
 *                                                                         *
 *  This program is free software; you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation; either version 2 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  This program is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 * The Authors are:                                                        *
 *                                                                         *
 * Geoffrey Keating <geoffk@ozemail.com.au>                                *
 *   Implemented first version of chrpath.c based on first version of      *
 *   killrpath.                                                            *
 * Peeter Joot <peeterj@ca.ibm.com>                                        *
 *   Implemented first version of killrpath.c.                             *
 * Petter Reinholdtsen <pere@hungry.com>                                   *
 *   Collected both implementations and made userfriendly wrapper.         *
 *                                                                         *
 * With patches from:                                                      *
 *                                                                         *
 * Darren Salt <linux@youmustbejoking.demon.co.uk>                         *
 * David Hull <hull@paracel.com>                                           *
 * Bradford W. Johnson <bradford@math.umn.edu>                             *
 * Thomas Anders <anders@hmi.de>                                           *
 * Tollef Fog Heen <tollef@add.no>                                         *
 *                                                                         *
 ***************************************************************************/


/* config.h.  Generated by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if you have the <elf.h> header file. */
#define HAVE_ELF_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the `getopt_long' function. */
#define HAVE_GETOPT_LONG 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <link.h> header file. */
#define HAVE_LINK_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/link.h> header file. */
/* #undef HAVE_SYS_LINK_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Name of package */
#define PACKAGE "chrpath"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "pere@hungry.com"

/* Define to the full name of this package. */
#define PACKAGE_NAME ""chrpath""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""chrpath" "0.13""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "-chrpath-"

/* Define to the version of this package. */
#define PACKAGE_VERSION ""0.13""

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "0.13"

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */
#ifndef PROTOS_H
#define PROTOS_H

#include <elf.h>
//#include "config.h"

#ifdef WORDS_BIGENDIAN
#define ELFDATA2 ELFDATA2MSB
#else
#define ELFDATA2 ELFDATA2LSB
#endif
#if SIZEOF_VOID_P == 8
#define Elf_Ehdr Elf64_Ehdr
#define ELFCLASS ELFCLASS64
#define Elf_Phdr Elf64_Phdr
#define Elf_Shdr Elf64_Shdr
#define Elf_Dyn  Elf64_Dyn
#elif SIZEOF_VOID_P == 4
#define Elf_Ehdr Elf32_Ehdr
#define ELFCLASS ELFCLASS32
#define Elf_Phdr Elf32_Phdr
#define Elf_Shdr Elf32_Shdr
#define Elf_Dyn  Elf32_Dyn
#else
#error "Unknown word size (SIZEOF_VOID_P)!"
#endif

int killrpath(const char *filename);
int chrpath(const char *filename, const char *newpath, int convert);

int elf_open(const char *filename, int flags, Elf_Ehdr *ehdr);
void elf_close(int fd);
int elf_find_dynamic_section(int fd, Elf_Ehdr *ehdr, Elf_Phdr *phdr);
const char *elf_tagname(int tag);
int elf_dynpath_tag(int tag);

#endif /* PROTOS_H */
/*
<URL:http://gcc.gnu.org/ml/gcc/1999-04n/msg01105.html>

Re: changing embedded RPATH in existing executables.

  To: geoffk@ozemail.com.au
  Subject: Re: changing embedded RPATH in existing executables.
  From: <peeter_joot@VNET.IBM.COM> (peeter joot)
  Date: Fri, 30 Apr 1999 16:14:44 -0400 (EDT)
  Cc: peeterj@ca.ibm.com, egcs@cygnus.com, libc-hacker@cygnus.com, linux-gcc@vger.rutgers.edu
  Reply-To: <peeter_joot@VNET.IBM.COM>

> _Changing_ is a little tricky, but the attached program strips rpaths
> from executables (I find it essential for debugging the binutils).
> It's endian-dependent, if you want this for x86 you can just change
> the occurrences of 'MSB' to 'LSB' and compile (I should really fix
> that).

Hi Geoff,

With your program as a guide (and some peeks into libbfd, elf.h, a bit
of the glibc dynamic loader code, objdump, and a hex-editor) I was able to
figure out enough to find and change the rpath string.  That was fun!

This program assumes (unlike your original program) that there is only
one DT_RPATH tag in the dynamic section as even with multiple '-Wl,-rpath,'
commands in the link this seems to occur (they all get concatenated into
a : separated path).

Thanks for your help.  If you want to use this on non-x86 you have to change
the occurrences of LSB back to MSB:)

Peeter
--
*/

#ifdef HAVE_CONFIG_H
//#  include "config.h"
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#if defined(HAVE_LINK_H)
#  include <link.h>
#endif /* HAVE_LINK_H */
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
//#include "protos.h"

/**
 * Reads an ELF file, and reads or alters the RPATH setting.
 *
 * TODO:
 *  modify to add RPATH setting if none exists.
 */


int
chrpath(const char *filename, const char *newpath, int convert)
{
  int fd;
  Elf_Ehdr ehdr;
  int i;
  Elf_Phdr phdr;
  Elf_Shdr shdr;
  Elf_Dyn *dyns;
  int rpathoff;
  char * strtab;
  char * rpath;
  unsigned int rpathlen;
  int oflags;
  int rpath_dyns_index;

  if (NULL == newpath && 0 == convert)
     oflags = O_RDONLY;
  else
     oflags = O_RDWR;

  fd = elf_open(filename, oflags, &ehdr);
  if (fd == -1)
  {
    perror ("elf_open");
    return 1;
  }

   if (0 != elf_find_dynamic_section(fd, &ehdr, &phdr))
   {
     perror("found no dynamic section");
     return 1;
   }

  dyns = malloc(phdr.p_filesz);
  if (dyns == NULL)
    {
      perror ("allocating memory for dynamic section");
      return 1;
    }
  memset(dyns, 0, phdr.p_filesz);
  if (lseek(fd, phdr.p_offset, SEEK_SET) == -1
      || read(fd, dyns, phdr.p_filesz) != (int)phdr.p_filesz)
    {
      perror ("reading dynamic section");
      free(dyns);
      return 1;
    }

  rpathoff = -1;
  for ( rpath_dyns_index = 0; dyns[rpath_dyns_index].d_tag != DT_NULL;
        ++rpath_dyns_index )
    {
      if ( elf_dynpath_tag(dyns[rpath_dyns_index].d_tag) )
      {
         rpathoff = dyns[rpath_dyns_index].d_un.d_ptr;
         break;
      }
    }
  if (rpathoff == -1)
    {
      printf("%s: no rpath or runpath tag found.\n", filename);
      free(dyns);
      return 2;
    }

  if (lseek(fd, ehdr.e_shoff, SEEK_SET) == -1)
  {
    perror ("positioning for sections");
    free(dyns);
    return 1;
  }

  for (i = 0; i < ehdr.e_shnum; ++i)
  {
    if (read(fd, &shdr, sizeof(shdr)) != sizeof(shdr))
    {
      perror ("reading section header");
      free(dyns);
      return 1;
    }
    if (shdr.sh_type == SHT_STRTAB)
      break;
  }
  if (i == ehdr.e_shnum)
    {
      fprintf (stderr, "No string table found.\n");
      free(dyns);
      return 2;
    }
  strtab = (char *)malloc(shdr.sh_size);
  if (strtab == NULL)
    {
      perror ("allocating memory for string table");
      free(dyns);
      return 1;
    }
  memset(strtab, 0, shdr.sh_size);

  if (lseek(fd, shdr.sh_offset, SEEK_SET) == -1)
  {
    perror ("positioning for string table");
    free(strtab);
    free(dyns);
    return 1;
  }
  if (read(fd, strtab, shdr.sh_size) != (int)shdr.sh_size)
  {
    perror ("reading string table");
    free(strtab);
    free(dyns);
    return 1;
  }

  if ((int)shdr.sh_size < rpathoff)
  {
    fprintf(stderr, "%s string offset not contained in string table",
            elf_tagname(dyns[rpath_dyns_index].d_tag));
    free(strtab);
    free(dyns);
    return 5;
  }
  rpath = strtab+rpathoff;

#if defined(DT_RUNPATH)
  if (convert && dyns[rpath_dyns_index].d_tag == DT_RPATH)
  {
    dyns[rpath_dyns_index].d_tag = DT_RUNPATH;
    if (lseek(fd, phdr.p_offset, SEEK_SET) == -1
        || write(fd, dyns, phdr.p_filesz) != (int)phdr.p_filesz)
    {
      perror ("converting RPATH to RUNPATH");
      return 1;
    }
    printf("%s: RPATH converted to RUNPATH\n", filename);
  }
#endif /* DT_RUNPATH */

  printf("%s: %s=%s\n", filename, elf_tagname(dyns[rpath_dyns_index].d_tag),
         rpath);

  if (NULL == newpath)
  {
    free(dyns);
    free(strtab);
    return 0;
  }

  rpathlen = strlen(rpath);

  /*
   * Calculate the maximum rpath length (will be equal to rpathlen unless
   * we have previously truncated it).
   */
  for ( i = rpathoff + rpathlen ; (i < (int)shdr.sh_size
                                   && strtab[i] == '\0') ; i++ )
    ;
  i--;

  if (i > (int)(rpathoff + rpathlen))
     rpathlen = i - rpathoff;

  if (strlen(newpath) > rpathlen)
  {
    fprintf(stderr, "new rpath '%s' too large; maximum length %u\n",
            newpath, rpathlen);
    free(dyns);
    free(strtab);
    return 7;
  }

  memset(rpath, 0, rpathlen);
  strcpy(rpath, newpath);

  if (lseek(fd, shdr.sh_offset+rpathoff, SEEK_SET) == -1)
  {
    perror ("positioning for RPATH");
    free(dyns);
    free(strtab);
    return 1;
  }
  if (write(fd, rpath, rpathlen) != (int)rpathlen)
  {
    perror ("writing RPATH");
    free(dyns);
    free(strtab);
    return 1;
  }
  printf("%s: new %s: %s\n", filename,
         elf_tagname(dyns[rpath_dyns_index].d_tag), rpath);

  elf_close(fd);

  free(dyns);
  dyns = NULL;

  free(strtab);

  return 0;
}

#ifdef HAVE_CONFIG_H
//#  include "config.h"
#endif

#include <elf.h>
#if defined(HAVE_SYS_LINK_H)
#  include <sys/link.h> /* Find DT_RPATH on Solaris 2.6 */
#endif /*  HAVE_SYS_LINK_H */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
//#include "protos.h"

int
elf_open(const char *filename, int flags, Elf_Ehdr *ehdr)
{
   int fd;

   fd = open(filename, flags);
   if (fd == -1)
   {
     perror ("open");
     return -1;
   }

   if (read(fd, ehdr, sizeof(*ehdr)) != sizeof(*ehdr))
   {
     perror ("reading header");
     close(fd);
     return -1;
   }

   if (0 != memcmp(ehdr->e_ident, ELFMAG, SELFMAG) ||
       ehdr->e_ident[EI_CLASS] != ELFCLASS ||
       ehdr->e_ident[EI_DATA] != ELFDATA2 ||
       ehdr->e_ident[EI_VERSION] != EV_CURRENT)
   {
     fprintf(stderr,
#ifdef WORDS_BIGENDIAN
             "`%s' probably isn't a %d-bit MSB-first ELF file.\n",
#else /* not WORD_BIGENDIAN */
             "`%s' probably isn't a %d-bit LSB-first ELF file.\n",
#endif /* not WORD_BIGENDIAN */
             filename, SIZEOF_VOID_P * 8);
     close(fd);
     errno = ENOEXEC; /* Hm, is this the best errno code to use? */
     return -1;
   }

   if (ehdr->e_phentsize != sizeof(Elf_Phdr))
   {
     fprintf(stderr, "section size was read as %d, not %d!\n",
            ehdr->e_phentsize, (int)sizeof(Elf_Phdr));
     close(fd);
     return -1;
   }
   return fd;
}

int
elf_find_dynamic_section(int fd, Elf_Ehdr *ehdr, Elf_Phdr *phdr)
{
  int i;
  if (lseek(fd, ehdr->e_phoff, SEEK_SET) == -1)
  {
    perror ("positioning for sections");
    return 1;
  }

  for (i = 0; i < ehdr->e_phnum; ++i)
  {
    if (read(fd, phdr, sizeof(*phdr)) != sizeof(*phdr))
    {
      perror ("reading section header");
      return 1;
    }
    if (phdr->p_type == PT_DYNAMIC)
      break;
  }
  if (i == ehdr->e_phnum)
    {
      fprintf (stderr, "No dynamic section found.\n");
      return 2;
    }

  if (0 == phdr->p_filesz)
    {
      fprintf (stderr, "Length of dynamic section is zero.\n");
      return 3;
    }

  return 0;
}

void
elf_close(int fd)
{
  close(fd);
}

const char *
elf_tagname(int tag)
{
  switch (tag) {
  case DT_RPATH:
    return "RPATH";
    break;
#if defined(DT_RUNPATH)
  case DT_RUNPATH:
    return "RUNPATH";
    break;
#endif /* DT_RUNPATH */
  }
  return "UNKNOWN";
}

int
elf_dynpath_tag(int tag)
{
  return ( tag == DT_RPATH
#if defined(DT_RUNPATH)
           || tag == DT_RUNPATH
#endif /* DT_RUNPATH */
           );
}
/*
Taken from another list:

_Changing_ is a little tricky, but the attached program strips rpaths
from executables (I find it essential for debugging the binutils).
It's endian-dependent, if you want this for x86 you can just change
the occurrences of 'MSB' to 'LSB' and compile (I should really fix
that).

--
Geoffrey Keating <geoffk@ozemail.com.au>
*/

#ifdef HAVE_CONFIG_H
//#  include "config.h"
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#if defined(HAVE_LINK_H)
#  include <link.h>
#endif /* HAVE_LINK_H */
#include <stdlib.h>
//#include "protos.h"
#include <string.h>

/* Reads an ELF file, nukes all the RPATH entries. */

int
killrpath(const char *filename)
{
   int fd;
   Elf_Ehdr ehdr;
   int i;
   Elf_Phdr phdr;
   Elf_Dyn *dyns;
   int dynpos;

   fd = elf_open(filename, O_RDWR, &ehdr);

   if (fd == -1)
   {
     perror ("elf_open");
     return 1;
   }

   if (0 != elf_find_dynamic_section(fd, &ehdr, &phdr))
   {
     perror("found no dynamic section");
     return 1;
   }

   dyns = malloc(phdr.p_memsz);
   if (dyns == NULL)
     {
       perror ("allocating memory for dynamic section");
       return 1;
     }
   memset(dyns, 0, phdr.p_memsz);
   if (lseek(fd, phdr.p_offset, SEEK_SET) == -1
       || read(fd, dyns, phdr.p_filesz) != (int)phdr.p_filesz)
     {
       perror ("reading dynamic section");
       return 1;
     }

   dynpos = 0;
   for (i = 0; dyns[i].d_tag != DT_NULL; ++i)
     {
       dyns[dynpos] = dyns[i];
       if ( ! elf_dynpath_tag(dyns[i].d_tag) )
        dynpos++;
     }
   for (; dynpos < i; ++dynpos)
     dyns[dynpos].d_tag = DT_NULL;

   if (lseek(fd, phdr.p_offset, SEEK_SET) == -1
       || write(fd, dyns, phdr.p_filesz) != (int)phdr.p_filesz)
     {
       perror ("writing dynamic section");
       return 1;
     }

   elf_close(fd);

   return 0;
}
/*
 * Author: Petter Reinholdtsen <pere@hungry.com>
 * date:   2001-01-20
 *
 * Alter ELF rpath information (insert, modify, remove).
 *
 * Based on source from Peeter Joot <peeterj@ca.ibm.com> and Geoffrey
 * Keating <geoffk@ozemail.com.au>.
 */

#ifdef HAVE_CONFIG_H
//#  include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif
//#include "protos.h"

#ifdef HAVE_GETOPT_LONG
#  define GETOPT_LONG getopt_long

static struct option long_options[] =
{
  {"convert",   0, 0, 'c'},
  {"delete",    0, 0, 'd'},
  {"help",      0, 0, 'h'},
  {"keepgoing", 0, 0, 'k'},
  {"list",      0, 0, 'l'},
  {"replace",   1, 0, 'r'},
  {"version",   0, 0, 'v'}
};

#else /* not HAVE_GETOPT_LONG */
#  define GETOPT_LONG(argc,argv,optstr,lopts,lidx) getopt(argc,argv,optstr)
#endif /* not HAVE_GETOPT_LONG */

static void
usage(char *progname)
{
  printf("Usage: %s [-v|-d|-c|-r <path>] <program> [<program> ...]\n\n",
         progname);
  printf("   -v|--version                Display program version number\n");
  printf("   -d|--delete                 Delete current rpath/runpath setting\n");
#if defined(DT_RUNPATH)
  printf("   -c|--convert                Convert rpath to runpath\n");
#endif /* DT_RUNPATH */
  printf("   -r <path>|--replace <path>  Replace current rpath/runpath setting\n");
  printf("                               with the path given\n");
  printf("   -l|--list                   List the current rpath/runpath (default)\n");
  printf("   -h|--help                   Show this usage information.\n");
#ifndef HAVE_GETOPT_LONG
  printf("\n *** The long options are not available on this platform");
#endif /* not HAVE_GETOPT_LONG */
#if !defined(DT_RUNPATH)
  printf("\n *** There is no support for runpath on this platform");
#endif /* DT_RUNPATH */
  printf("\n");
}

int
main(int argc, char * const argv[])
{
  int retval = 0;
  int convert = 0;      /* convert to given type */
  int remove = 0;       /* remove or not */
  int keep_going = 0;   /* Break on first error, or keep going? */
  char *newpath = NULL; /* insert this path */
  int opt;
#ifdef HAVE_GETOPT_LONG
  int option_index = 0;
#endif /* HAVE_GETOPT_LONG */

  if (argc < 2)
    {
      usage(argv[0]);
      return 1;
    }

  do {
    opt = GETOPT_LONG(argc, argv, "cdhklr:v", long_options, &option_index);
    switch (opt)
      {
#if defined(DT_RUNPATH)
      case 'c':
        convert = 1;
        break;
#endif /* DT_RUNPATH */
      case 'd':
        remove = 1;
        break;
      case 'k':
        keep_going = 1;
        break;
      case 'r':
        newpath = optarg;
        break;
      case 'v':
        printf("%s version %s\n", PACKAGE, VERSION);
        exit(0);
        break;
      case 'l': /* This is the default action */
        newpath = NULL;
        break;
      case -1:
        break;
      default:
        printf("Invalid argument '%c'\n", opt);
      case 'h':
        usage(argv[0]);
        exit(0);
        break;
      }
  } while (-1 != opt);

  while (optind < argc && (!retval || keep_going))
    {
      if (remove)
        retval |= killrpath(argv[optind++]);
      else
        /* list by default, replace if path is set */
        retval |= chrpath(argv[optind++], newpath, convert);
    }

  return retval;
}
