#include "main.h"

/**
  * **parse_str - splits the string entered by the user.
  * @buffer: string to be split.
  * Return: the splitted string.
  */
char **parse_str(char *buffer)
{
	char **input_str = NULL;
	char *token, *delim = " \n";
	int tt;

	input_str = malloc(sizeof(char *) * 1024);
	if (input_str == NULL)
	{
		perror("memory could not be allocated");
		exit(EXIT_FAILURE);
	}
	token = strtok(buffer, delim);
	tt = 0;
	while (token != NULL)
	{
		input_str[tt] = token;
		token = strtok(NULL, delim);
		tt++;
	}
	input_str[tt] = NULL;
	return (input_str);
}
