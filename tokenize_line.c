#include "main.h"

/**
 * tokenize_line - Splits a command line into an array of arguments
 * @line: the input string to be tokenized using strtok
 * Return: NULL if allocation fails, or a NULL-terminated array of strings
 *         (each string is an argument, and must be freed afterwards)
 */

char **tokenize_line(char *line)
{
	char **words_token;
	char *word_token;
	int i = 0;

	words_token = malloc(65 * sizeof(char *));

	if (words_token == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	word_token = strtok(line, " \n");

	while (word_token != NULL)
	{
		words_token[i] = strdup(word_token);
		if (words_token[i] == NULL)
		{
			perror("strdup");
			while (i-- > 0)
			{
				free(words_token[i]);
			}
			free(words_token);
			return (NULL);
		}
		i++;
		word_token = strtok(NULL, " \n");
	}
	words_token[i] = NULL;
	return (words_token);
}
