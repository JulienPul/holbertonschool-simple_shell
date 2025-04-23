#include "main.h"

/**
 * execute_commande - Fonction qui exécute une commande avec ses arguments
 * @commande: tableau d’arguments, commande[0] étant le programme
 */

void execute_commande(char **commande)
{
	pid_t pid_enfant;
	int status;

	pid_enfant = fork();

	if (pid_enfant == -1)
	{
		perror("fork");
		return;
	}

	if (pid_enfant == 0)
	{
		if (execve(commande[0], commande, environ) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", commande[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}
