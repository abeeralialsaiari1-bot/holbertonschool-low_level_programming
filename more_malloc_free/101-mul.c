#include <stdlib.h>
#include <stdio.h>

int _putchar(char c);

/**
 * is_digit - checks if a string contains a non-digit
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
	printf("Error\n");
	exit(98);
}

/**
 * _print - prints the array result
 * @result: the array
 * @len: length of the array
 */
void _print(int *result, int len)
{
	int i, a = 0;

	for (i = 0; i < len; i++)
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
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *s1, *s2;
	int len1, len2, len, i, j, carry, digit1, digit2, *result;

	if (argc != 3)
		errors();
	s1 = argv[1], s2 = argv[2];
	if (s1[0] == '\0' || s2[0] == '\0' || !is_digit(s1) || !is_digit(s2))
		errors();
	len1 = _strlen(s1), len2 = _strlen(s2), len = len1 + len2;
	result = malloc(sizeof(int) * len);
	if (!result)
		return (1);
	for (i = 0; i < len; i++)
		result[i] = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		digit1 = s1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = s2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}
	_print(result, len);
	free(result);
	return (0);
}
