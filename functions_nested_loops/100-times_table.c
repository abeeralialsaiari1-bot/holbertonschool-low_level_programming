#include "main.h"
/**
 * print_times_table - prints n times table
 * @n: table size
 */
void print_times_table(int n)
{
	int i, j, res;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			_putchar('0');
			for (j = 1; j <= n; j++)
			{
				res = i * j;
				_putchar(',');
				_putchar(' ');
				if (res <= 9)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else if (res <= 99)
					_putchar(' ');
				else
					_putchar((res / 100) + '0');
				if (res > 99)
					_putchar(((res / 10) % 10) + '0');
				else if (res > 9)
					_putchar((res / 10) + '0');
				_putchar((res % 10) + '0');
			}
			_putchar('\n');
		}
	}
}
