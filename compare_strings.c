#include "main.h"

/**
  * string_compare - compares two strings
  * @s1: the first string
  * @s2: second string
  * Return: difference of the two strings
  */
int string_compare(char *s1, char *s2)
{
	int result;
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			break;
		}
		i++;
	}
	result = s1[i] - s2[i];
	return (result);
}
