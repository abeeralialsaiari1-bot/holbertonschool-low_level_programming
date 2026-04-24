#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Keygen for crackme5.
 * @argc: The number of arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char key[7];
	char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZe0i1rmu71K3doKW";
	char *name = argv[1];
	int i, sum = 0, mul = 1, tmp = 0;

	if (argc != 2)
		return (1);

	for (i = 0; name[i]; i++)
		sum += name[i];
	key[0] = lookup[(sum ^ 59) & 63];

	for (i = 0; name[i]; i++)
		mul *= name[i];
	key[1] = lookup[(mul ^ 79) & 63];

	for (i = 0; name[i]; i++)
	{
		if (name[i] > tmp)
			tmp = name[i];
	}
	srand(tmp ^ 14);
	key[2] = lookup[rand() & 63];

	for (tmp = 0, i = 0; name[i]; i++)
		tmp += (name[i] * name[i]);
	key[3] = lookup[(tmp ^ 239) & 63];

	for (tmp = 0, i = 0; i < name[0]; i++)
		tmp = rand();
	key[4] = lookup[(tmp ^ 229) & 63];

	for (tmp = 0, i = 0; name[i]; i++)
		tmp += rand();
	key[5] = lookup[(tmp ^ 255) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
