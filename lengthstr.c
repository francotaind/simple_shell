#include "main.h"

/**
  * str_len - finds the length of a string.
  * Return: length of f.
  * @pointer: pointer.
  */
int str_len(char *pointer)
{
	int f = 0;

	while (*(pointer + f) != '\0')
	{
		f++;
	}
	return (f);
}
