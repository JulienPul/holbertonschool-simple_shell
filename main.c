#include "main.h"
/**
 * main - main function for comand interpretor
 * Return: 0 if succes
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **argv;

	while (1)
	{
		/* Affiche le prompt seulement si entrée clavier */
		if (isatty(STDIN_FILENO))
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			if (isatty(STDIN_FILENO))
				printf("\n");
			break;
		}

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		argv = tokenize_line(line);
		if (argv[0] != NULL)
			execute_command(argv);
	}

	free(line);
	return (0);
}
