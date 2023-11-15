#include "main.h"
/**
 * *str_loc - locates a character in a string.
 * @s: string.
 * @j: character to be located.
 * Return: pointer to first occurrence of NULL if no character found.
 */
char *str_locater(char *s, char j)
{
	while (*s != '\0')
	{
		if (*s == j)
		{
			return (s);
		}
		s++;
	}
	return (0);
}
