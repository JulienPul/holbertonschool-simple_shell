#include "main.h"

/**
 * boucle_principale - boucle principale du shell version 0.1
 */

void boucle_principale(void)
{
	char *ligne_tapee = NULL;
	size_t taille_buffer_getline = 0;
	ssize_t lu;

	while (1)
	{
		write (STDOUT_FILENO, "$ ", 2);
		lu = getline(&ligne_tapee, &taille_buffer_getline, stdin);

		if (lu == -1) /* Ctrl+D ou EOF*/
		{
			free(ligne_tapee);
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (ligne_tapee[lu - 1] == '\n')
			ligne_tapee[lu - 1] = '\0';

		if (ligne_tapee[0] != '\0') /* Ignore les lignes vides */
			executer_commande(ligne_tapee);
	}
	free(ligne_tapee);
}
