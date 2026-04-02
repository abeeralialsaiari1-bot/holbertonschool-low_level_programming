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
	{
		i++;
	}
	return (i);
}

/**
 * errors - handles errors for main
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
 * print_result - prints the array
 * @result: array of integers
 * @len: length of the array
 */
void print_result(int *result, int len)
{
	int i, a = 0;

	for (i = 0; i < len - 1; i++)
	{
		if (result[i])
			a = 1;
		if (a)
			_putchar(result[i] + '0');
	}
	if (!a)
		_putchar('0');
	_putchar('\n');
}

/**
 * multiply - multiplies two strings and prints the result
 * @s1: first string
 * @s2: second string
 */
void multiply(char *s1, char *s2)
{
	int len1, len2, len, carry;
	int *result;

	len1 = _strlen(s1);
	len2 = _strlen(s2);
	len = len1 + len2 + 1;
	result = malloc(sizeof(int) * len);
	if (!result)
		exit(98);
	for (carry = 0; carry < len; carry++)
		result[carry] = 0;
	for (len1 = len1 - 1; len1 >= 0; len1--)
	{
		carry = 0;
		for (len2 = _strlen(s2) - 1; len2 >= 0; len2--)
		{
			carry += result[len1 + len2 + 1];
			carry += (s1[len1] - '0') * (s2[len2] - '0');
			result[len1 + len2 + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[len1 + len2 + 1] += carry;
	}
	print_result(result, len);
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
