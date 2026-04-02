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
	int i;

	i = 0;
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
	int i;

	i = 0;
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
	char *err1;
	int i;

	err1 = "Error";
	i = 0;
	while (err1[i])
	{
		_putchar(err1[i]);
		i++;
	}
	_putchar('\n');
	exit(98);
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
	for (carry = 0; carry <= len1 + len2; carry++)
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
	carry = 0;
	for (len1 = 0; len1 < len - 1; len1++)
	{
		if (result[len1])
			carry = 1;
		if (carry)
			_putchar(result[len1] + '0');
	}
	if (!carry)
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
	char *s1, *s2;

	if (argc != 3)
		errors();
	if (!is_digit(argv[1]) || !is_digit(argv[2]))
		errors();
	s1 = argv[1];
	s2 = argv[2];
	multiply(s1, s2);
	return (0);
}
