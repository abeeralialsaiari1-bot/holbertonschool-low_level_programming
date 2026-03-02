#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: buffer size
 *
 * Return: pointer to result or 0
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, k, l = 0, m, n, add = 0;

	while (n1[i])
		i++;
	while (n2[j])
		j++;
	if (i > size_r || j > size_r)
		return (0);
	m = i - 1;
	n = j - 1;
	r[size_r - 1] = '\0';
	for (k = size_r - 2; k >= 0; k--)
	{
		add += (m >= 0 ? n1[m--] - '0' : 0) + (n >= 0 ? n2[n--] - '0' : 0);
		r[k] = (add % 10) + '0';
		add /= 10;
		l++;
		if (m < 0 && n < 0 && add == 0)
			break;
	}
	if (add != 0)
		return (0);
	if (l >= size_r)
		return (0);
	for (i = 0; i <= l; i++)
		r[i] = r[k + i];
	return (r);
}
