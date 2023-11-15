#include "main.h"
/**
  * main - entry point
  * @ac: argument count
  * @avector: argument vector
  * @envp: array of strings.
  * Return: 0 (success)
  */
int main(int ac __attribute__((unused)), char *avector[], char *envp[])
{
	char *buff = NULL;
	pid_t child_pid;
	size_t bufsize = 0;
	int status;
	const char *message = "cotashell$";

	signal(SIGINT, SIG_IGN);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, message, strlen(message));
		if (getline(&buff, &bufsize, stdin) == -1)
			break;
		if (buff == NULL)
			exit(0);
		avector = parse_str(buff);
		if (!avector[0])
		{
			free(avector);
			continue;
		}
		if (string_compare(avector[0], "env") == 0)
		{
			print_environ(), free(avector);
			continue;
		}
		if (string_compare(avector[0], "exit") == 0)
			free(avector), free(buff), exit(0);
		child_pid = fork();
		if (child_pid == 0)
		{
			if (str_locater(avector[0], '/') == NULL)
				avector[0] = path_search(avector[0]);
			if (execve(avector[0], avector, envp))
			{
				perror("execve"), exit(EXIT_FAILURE);
				break;
			}
		}
		wait(&status), free(avector);
	}
	free(buff);
	return (0);
}
