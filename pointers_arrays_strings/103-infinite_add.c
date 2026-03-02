#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char temp;

	while (s[i] != '\0')
		i++;
	i--;

	for (j = 0; j < i; j++, i--)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer for result
 * @size_r: buffer size
 *
 * Return: pointer to the result or 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k = 0, carry = 0, val1, val2;

	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;

	i--;
	j--;

	if (i + 2 > size_r || j + 2 > size_r)
		return (0);

	while (i >= 0 || j >= 0 || carry)
	{
		val1 = (i >= 0) ? n1[i] - '0' : 0;
		val2 = (j >= 0) ? n2[j] - '0' : 0;

		if (k >= size_r - 1)
			return (0);

		r[k++] = ((val1 + val2 + carry) % 10) + '0';
		carry = (val1 + val2 + carry) / 10;
		i--;
		j--;
	}

	r[k] = '\0';
	rev_string(r);

	return (r);
}
