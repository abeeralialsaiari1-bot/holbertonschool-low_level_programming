#include "main.h"
#include <stdlib.h>

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	if (!s || s[0] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * errors - handles errors for main and exits with 98
 */
void errors(void)
{
	char *err = "Error\n";
	int i = 0;

	while (err[i])
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

/**
 * multiply - multiplies two strings of numbers
 * @s1: first string
 * @s2: second string
 */
void multiply(char *s1, char *s2)
{
	int len1, len2, len, i, j, res, carry;
	int *result;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2;
	result = malloc(sizeof(int) * len);
	if (!result)
		exit(98);
	for (i = 0; i < len; i++)
		result[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			res = (s1[i] - '0') * (s2[j] - '0') + result[i + j + 1] + carry;
			carry = res / 10;
			result[i + j + 1] = res % 10;
		}
		result[i + j + 1] += carry;
	}
	res = 0;
	for (i = 0; i < len; i++)
	{
		if (result[i])
			res = 1;
		if (res)
			_putchar(result[i] + '0');
	}
	if (!res)
		_putchar('0');
	_putchar('\n');
	free(result);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
		errors();
	multiply(argv[1], argv[2]);
	return (0);
}
