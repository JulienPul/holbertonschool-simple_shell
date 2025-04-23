#include "main.h"

/**
 * tokenize_line - Fonction qui tokenize une ligne en 1 tableau d'args
 * @line: chaîne à découper (tokenizer) par strtok
 * Return: Tableau NULL ou tableau de char* terminé par NULL (à free après)
 */
char **tokenize_line(char *line)
{
	char **mots_token;
	char *mot_token;
	int i = 0;

	mots_token = malloc(65 * sizeof(char *));

	if (mots_token == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	mot_token = strtok(line, " \n");

	while (mot_token != NULL)
	{
		mots_token[i] = strdup(mot_token);
		if (mots_token[i] == NULL)
		{
			perror("strdup");
			while (i-- > 0)
			{
				free(mots_token[i]);
			}
			free(mots_token);
			return (NULL);
		}
		i++;
		mot_token = strtok(NULL, " \n");
	}
	mots_token[i] = NULL;
	return (mots_token);
}
