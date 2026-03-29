#include "main.h"
#include <stdlib.h>
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;
	if (str == NULL)
		return (NULL);
	while (str[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}
