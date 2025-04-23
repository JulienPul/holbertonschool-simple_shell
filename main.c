#include "main.h"
/**
 * main - main function for command interpreter
 * @argc: argument count (unused)
 * @argv: argument vector, used to get program name
 * Return: 0 if success
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **argv = NULL;
	int i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ "), fflush(stdout);

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		argv = tokenize_line(line);
		if (argv && argv[0])
		{
			if (strcmp(argv[0], "exit") == 0)
				break;
			execute_command(argv, argv[0]);
		}
		if (argv)
		{
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
		}
	}
	free(line);
	return (0);
}
