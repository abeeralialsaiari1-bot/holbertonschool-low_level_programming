#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned char *e_ident, unsigned char *e_type_p);
void print_entry(unsigned char *e_ident, unsigned char *e_entry_p);
void close_elf(int elf);

void check_elf(unsigned char *e_ident)
{
	if (e_ident[0] != 127 || e_ident[1] != 'E' ||
	    e_ident[2] != 'L' || e_ident[3] != 'F')
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

void print_magic(unsigned char *e_ident)
{
	int index;

	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}

void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);
	if (e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

void print_type(unsigned char *e_ident, unsigned char *e_type_p)
{
	unsigned int type;

	if (e_ident[EI_DATA] == ELFDATA2MSB)
		type = (e_type_p[0] << 8) | e_type_p[1];
	else
		type = (e_type_p[1] << 8) | e_type_p[0];

	printf("  Type:                              ");
	switch (type)
	{
	case ET_NONE: printf("NONE (None)\n"); break;
	case ET_REL: printf("REL (Relocatable file)\n"); break;
	case ET_EXEC: printf("EXEC (Executable file)\n"); break;
	case ET_DYN: printf("DYN (Shared object file)\n"); break;
	case ET_CORE: printf("CORE (Core file)\n"); break;
	default: printf("<unknown: %x>\n", type);
	}
}

void print_entry(unsigned char *e_ident, unsigned char *e_entry_p)
{
	int i;
	int size = (e_ident[EI_CLASS] == ELFCLASS32) ? 4 : 8;

	printf("  Entry point address:               0x");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		i = 0;
		while (i < size && e_entry_p[i] == 0) i++;
		if (i == size) printf("0");
		for (; i < size; i++) printf("%x", e_entry_p[i]);
	}
	else
	{
		i = size - 1;
		while (i >= 0 && e_entry_p[i] == 0) i--;
		if (i == -1) printf("0");
		for (; i >= 0; i--) printf("%02x", e_entry_p[i]);
	}
	printf("\n");
}

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

int main(int argc, char *argv[])
{
	Elf64_Ehdr h;
	int fd, r;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(fd, &h, sizeof(h));
	if (r < 1 || (unsigned int)r < EI_NIDENT)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: read failed\n");
		exit(98);
	}
	check_elf(h.e_ident);
	printf("ELF Header:\n");
	print_magic(h.e_ident);
	print_class(h.e_ident);
	print_data(h.e_ident);
	print_version(h.e_ident);
	print_osabi(h.e_ident);
	print_abi(h.e_ident);
	print_type(h.e_ident, (unsigned char *)&h.e_type);
	print_entry(h.e_ident, (unsigned char *)&h.e_entry);
	close_elf(fd);
	return (0);
}
