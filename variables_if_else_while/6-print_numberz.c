#include <stdio.h>

/**
 * main - Prints 0-9 without char variables
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 48; i <= 57; i++)
		putchar(i);
	putchar('\n');
	return (0);
}
