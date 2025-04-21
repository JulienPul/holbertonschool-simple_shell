#include "main.h"

/**
 * main - Version petit shell qui imprimera qui exécute /bin/ls -l /tmp
 * Return: 0 si succès sinon retourne 1
 */

int main(void)
{
	char *ligne_lue = NULL;
	size_t taille_buffer = 0;
	ssize_t nb_caracteres_lus;
	pid_t pid_enfant;
	int statut;
	char *arguments[] = {"/bin/ls", "-l", "/tmp", NULL};

	while (1)
	{
		printf("$ ");

		nb_caracteres_lus = getline(&ligne_lue, &taille_buffer, stdin);

		if (nb_caracteres_lus == -1)
		{
			free(ligne_lue);
			exit(0);
		}

		pid_enfant = fork();

		if (pid_enfant == -1)
		{
			perror("fork");
			return (-1);
		}
		else if (pid_enfant == 0)
		{
			execve(arguments[0], arguments, environ);
			perror("execve");
			exit(1);
		}
		else
		{
			wait(&statut);
		}

	}
}
