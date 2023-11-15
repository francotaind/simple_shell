#include "main.h"

/**
  * *path_search - makes a complete path from path.
  * @input_str: command to make complete path from.
  * Return: complete path.
  */
char *path_search(char *input_str)
{
	char *path = NULL, *token = NULL, chs = '/';
	char *dirs[1024];
	int i = 0;
	char *cwd = getcwd(NULL, 0);
	struct stat cota;

	path = getenv("PATH");
	token = strtok(path, ":");
	if (dirs[0] == NULL)
		return NULL;

	while (token != NULL)
	{
		dirs[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	dirs[i] = NULL;

	i = 0;
	while (dirs[i] != NULL)
	{
		chdir(dirs[i]);
		if (stat(input_str, &cota) == 0)
		{
			dirs[i] = string_combine(dirs[i], &chs, 1);
			input_str = strjoin(dirs[i], input_str);
			break;
		}
		i++;
	}
	chdir(cwd);
	return (input_str);
}
