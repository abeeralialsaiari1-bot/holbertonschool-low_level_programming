#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *con;
	unsigned int i, j, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;

	con = malloc((len1 + len2 + 1) * sizeof(char));

	if (con == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		con[i] = s1[i];

	for (j = 0; j < len2; j++, i++)
		con[i] = s2[j];

	con[i] = '\0';

	return (con);
}
