#include "main.h"
/**
 * execute_command - Executes a command using execve, with PATH resolution
 * @argv: array of arguments (e.g. {"/bin/ls", "-l", NULL})
 * @program_name: name of the main program (argv[0]), used for error messages
 */

void execute_command(char **argv, char *program_name)
{
	int status;
	pid_t pid = fork();
	char *path_env, *path_copy, *dir;
	char full_path[1024];

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			path_env = _getenv("PATH");
			if (path_env != NULL)
			{
				path_copy = strdup(path_env);
				if (path_copy == NULL)
				{
					perror("strdup");
					exit(1);
				}
				dir = strtok(path_copy, ":");
				while (dir != NULL)
				{
					snprintf(full_path, sizeof(full_path), "%s/%s", dir, argv[0]);
					execve(full_path, argv, environ);

					dir = strtok(NULL, ":");
				}
				free(path_copy);
			}
			fprintf(stderr, "%s: %s: not found\n", program_name, argv[0]);
			exit(127);
		}
	}
	else if (pid == -1)
	{
		perror("fork:");
	}
	else
	{
		wait(&status);
	}
}
