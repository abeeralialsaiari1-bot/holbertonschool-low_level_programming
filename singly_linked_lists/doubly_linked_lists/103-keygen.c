#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates a key for crackme5
 * @argc: number of arguments
 * @argv: arguments passed
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char key[7];
	int len, i, v;
	char *codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}

	len = strlen(argv[1]);
	key[0] = codex[(len ^ 59) & 63];

	for (i = 0, v = 0; i < len; i++)
		v += argv[1][i];
	key[1] = codex[(v ^ 79) & 63];

	for (i = 0, v = 1; i < len; i++)
		v *= argv[1][i];
	key[2] = codex[(v ^ 85) & 63];

	for (i = 0, v = argv[1][0]; i < len; i++)
	{
		if (argv[1][i] > v)
			v = argv[1][i];
	}
	srand(v ^ 14);
	key[3] = codex[rand() & 63];

	for (i = 0, v = 0; i < len; i++)
		v += argv[1][i] * argv[1][i];
	key[4] = codex[(v ^ 239) & 63];

	for (i = 0, v = 0; i < argv[1][0]; i++)
		v = rand();
	key[5] = codex[(v ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
