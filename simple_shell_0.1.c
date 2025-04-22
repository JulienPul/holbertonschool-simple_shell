#include "main.h"

/**
 * main - Version petit shell 0.1
 * Return: 0 si succès sinon retourne 1
 */

int main(void)
{
	char *ligne_lue_tape = NULL;
	size_t taille_buffer_getline = 0;
	ssize_t nb_caracteres_lus;
	pid_t pid_enfant;
	int statut_fin_process_enfant;
	char *arguments_execve[2];

	while (1)
	{
		printf("$ ");
		nb_caracteres_lus = getline(&ligne_lue_tape, &taille_buffer_getline, stdin);

		if (nb_caracteres_lus == -1) /* Ctrl+D */
		{
			free(ligne_lue_tape);
			exit(0);
		}

		/* Supprimer le \n à la fin de la ligne lue */
		if (ligne_lue_tape[nb_caracteres_lus - 1] == '\n')
			ligne_lue_tape[nb_caracteres_lus - 1] = '\0';

		pid_enfant = fork();
		if (pid_enfant == -1)
		{
			perror("fork");
			free(ligne_lue_tape);
			exit(1);
		}
		else if (pid_enfant == 0)
		{
			arguments_execve[0] = ligne_lue_tape;
			arguments_execve[1] = NULL;
			if (execve(arguments_execve[0], arguments_execve, environ) == -1)
			{
				perror("./hsh");
				exit(1);
			}
		}
		else
		{
			wait(&statut_fin_process_enfant);
		}
	}

	free(ligne_lue_tape);
	return (0);
}
