#include "main.h"

/**
 * *strjoin - concatenates two strings.
 * @dest: resulting string.
 * @src: source string.
 * Return: pointer to dest
 */
char *strjoin(char *dest, char *src)
{
	int k, j;

	j = str_len(dest);
	for (k = 0; k < j && src[k] != '\0'; k++)
	{
		dest[j + k] = src[k];
	}
	dest[j + k] = '\0';
	return (dest);
}
