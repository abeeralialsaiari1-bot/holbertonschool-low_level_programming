#include <stdio.h>
/**
 * main - sum even Fibonacci below 4,000,000
 * Return: 0
 */
int main(void)
{
	long int a = 1, b = 2, next = 0, sum = 2;

	while (next <= 4000000)
	{
		next = a + b;
		if (next % 2 == 0)
			sum += next;
		a = b;
		b = next;
	}
	printf("%ld\n", sum);
	return (0);
}
