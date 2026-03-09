#include "main.h"

/**
 * _strlen_rec - finds the length of a string
 * @s: the string
 *
 * Return: the length
 */
int _strlen_rec(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + _strlen_rec(s + 1));
}

/**
 * check_palindrome - checks the characters recursively
 * @s: the string
 * @start: starting index
 * @end: ending index
 *
 * Return: 1 if palindrome, 0 if not
 */
int check_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (check_palindrome(s, start + 1, end - 1));
}

/**
 * is_palindrome - returns 1 if a string is a palindrome and 0 if not.
 * @s: the string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = _strlen_rec(s);

	if (len == 0)
		return (1);
	return (check_palindrome(s, 0, len - 1));
}
