#include "main.h"

/**
 * main - Petit shell qui lit une ligne et exécute la commande avec arguments
 * Return: 0 (Toujours)
 */

int main(void)
{
	char *ligne_lue = NULL;
	size_t taille_buffer = 0;
	ssize_t nb_caracteres_lus;
	pid_t pid_enfant;
	int statut;
	char *args[64];
	char *token;
	int i;

	while (1)
	{
		printf("$ ");

		nb_caracteres_lus = getline(&ligne_lue, &taille_buffer, stdin);
		if (nb_caracteres_lus == -1)
		{
			free(ligne_lue);
			exit(0);
		}

		/* Supprimer le saut de ligne */
		for (i = 0; ligne_lue[i]; i++)
		{
			if (ligne_lue[i] == '\n')
			{
				ligne_lue[i] = '\0';
				break;
			}
		}
		
		token = strtok(ligne_lue, " ");
		i = 0;
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		pid_enfant = fork();
		if (pid_enfant == -1)
		{
			perror("fork");
			return (-1);
		}
		else if (pid_enfant == 0)
		{
			execve(args[0], args, environ);
			perror("execve");
			exit(1);
		}
		else
		{
			wait(&statut);
		}
	}
}
