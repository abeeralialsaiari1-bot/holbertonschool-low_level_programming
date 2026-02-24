#include <stdio.h>
/**
 * main - prints first 98 Fibonacci numbers
 * Return: 0
 */
int main(void)
{
	unsigned long int i, a_h, a_l, b_h, b_l, n_h, n_l;
	unsigned long int lim = 1000000000;

	a_h = 0; a_l = 1; b_h = 0; b_l = 2;
	printf("%lu, %lu", a_l, b_l);
	for (i = 3; i <= 98; i++)
	{
		n_l = a_l + b_l;
		n_h = a_h + b_h + (n_l / lim);
		n_l %= lim;
		if (n_h > 0)
			printf(", %lu%09lu", n_h, n_l);
		else
			printf(", %lu", n_l);
		a_h = b_h; a_l = b_l;
		b_h = n_h; b_l = n_l;
	}
	printf("\n");
	return (0);
}
