#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        exit(98);
    }
    char buffer[16];
    if (read(fd, buffer, 16) != 16) {
        fprintf(stderr, "Failed to read ELF header from file %s\n", argv[1]);
        exit(98);
    }
    Elf64_Ehdr *elf_header = (Elf64_Ehdr *) buffer;
    if (elf_header->e_ident[EI_MAG0] != ELFMAG0
        || elf_header->e_ident[EI_MAG1] != ELFMAG1
        || elf_header->e_ident[EI_MAG2] != ELFMAG2
        || elf_header->e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "File %s is not an ELF file\n", argv[1]);
        exit(98);
    }
    printf("Magic:   %02x %02x %02x %02x\n", elf_header->e_ident[EI_MAG0], elf_header->e_ident[EI_MAG1], elf_header->e_ident[EI_MAG2], elf_header->e_ident[EI_MAG3]);
    printf("Class:                             %d-bit\n", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
    printf("Data:                              %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("Version:                           %d\n", elf_header->e_ident[EI_VERSION]);
    printf("OS/ABI:                            %s\n", elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX System V ABI" : "Others");
    printf("ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("Type:                              %s\n", elf_header->e_type == ET_EXEC ? "Executable file" : elf_header->e_type == ET_DYN ? "Shared object file" : "Others");
    printf("Entry point address:               %lx\n", elf_header->e_entry);
    close(fd);
    return 0;
}
