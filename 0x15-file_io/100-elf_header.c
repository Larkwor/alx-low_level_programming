#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_elf_header - prints the ELF header information of a file
 * @elf_fd: file descriptor of the ELF file
 */
void print_elf_header(int elf_fd)
{
    Elf64_Ehdr header;
    ssize_t bytes_read;

    /* Read ELF header */
    bytes_read = read(elf_fd, &header, sizeof(header));
    if (bytes_read != sizeof(header) || header.e_ident[EI_MAG0] != ELFMAG0
        || header.e_ident[EI_MAG1] != ELFMAG1
        || header.e_ident[EI_MAG2] != ELFMAG2
        || header.e_ident[EI_MAG3] != ELFMAG3)
    {
        fprintf(stderr, "Error: Not an ELF file\n");
        exit(98);
    }

    /* Print ELF header information */
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header.e_ident[i]);
    printf("\n");
    printf("  Class:                             %s\n",
           header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
           header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
           header.e_ident[EI_CLASS] == ELFCLASSNONE ? "none" : "unknown");
    printf("  Data:                              %s\n",
           header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
           header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "unknown");
    printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n",
           header.e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" :
           header.e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
           header.e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
           header.e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
           header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
           header.e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
           header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
           header.e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
           header.e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
           header.e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" : "UNIX - unknown");
    printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n",
           header.e_type == ET_NONE ? "NONE (None)" :
           header.e_type == ET_REL ? "REL (Relocatable file)" :
           header.e_type == ET_EXEC ? "EXEC (Executable file)" :
           header.e_type == ET_DYN ? "DYN (Shared object file)" :
           header.e_type == ET_CORE ? "CORE (
}
