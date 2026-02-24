#include <stdio.h>
/**
 * main - prints 0-9 using putchar
 * Return: Always 0
 */
int main(void)
{
	int i;

	for (i = 48; i < 58; i++)
		putchar(i);
	putchar('\n');
	return (0);
}
