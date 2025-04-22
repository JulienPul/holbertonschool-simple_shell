#include "main.h"
/**
 * execute_command - Exécute command with execve
 * @argv: array of arguments (ex: {"/bin/ls", "-l", NULL})
 */
void execute_command(char **argv)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
			exit(127);
		}
	}
	else if (pid == -1)
	{
		perror("fork");
	}
	else
	{
		wait(&status);
	}
}
