#include "main.h"

/**
 * tokenize_line - Fonction qui tokenize une ligne en 1 tableau d'args
 * @line: chaîne à découper (tokenizer) par strtok
 * Return: Tableau NULL ou tableau de char* terminé par NULL (à free après)
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
