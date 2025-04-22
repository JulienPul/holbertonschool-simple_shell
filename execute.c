#include "main.h"

/**
 * execute_command - Fonction qui execute une cde sans args ni PATH
 * @commande: chemin de la cde passée (ex: /bin/ls/tmp)
 */

void execute_commande(char *commande)
{
	pid_t pid_enfant;
	char *argv[2];
	argv[0] = commande;
	argv[1] = NULL;
	int status;

	pid_enfant = fork();

	if (pid_enfant == -1)
	{
		perror("fork");
		return;
	}

	if (pid_enfant == 0)

	{
		if (execve(commande, argv, environ) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
