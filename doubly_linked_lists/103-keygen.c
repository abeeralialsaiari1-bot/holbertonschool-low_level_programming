#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Generates a key for crackme5 based on a username.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	unsigned int i, sum;
	char *username;
	char *lookup = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZe0i1rmu71K3doKW";
	char key[7];

	if (argc != 2)
		return (1);

	username = argv[1];
	sum = 0;
	for (i = 0; i < strlen(username); i++)
		sum += username[i];

	key[0] = lookup[(sum ^ 59) & 63];
	key[1] = lookup[(sum ^ 79) & 63];
	key[2] = lookup[(sum ^ 85) & 63];
	key[3] = lookup[(sum ^ 110) & 63];
	key[4] = lookup[(sum ^ 125) & 63];
	key[5] = lookup[(sum ^ 113) & 63];
	key[6] = '\0';

	printf("%s", key);

	return (0);
}
