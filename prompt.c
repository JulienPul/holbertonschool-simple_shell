#include "main.h"

/**
 * boucle_principale - boucle principale du shell version 0.1 et 0.2
 */

void boucle_principale(void)
{
	char *ligne_tapee = NULL;
	size_t taille_buffer_getline = 0;
	ssize_t lu;
	char **arguments; /* variable qui va contenir les mots découpés */

	while (1)
	{
		/* Affiche le prompt que si l'entrée vient du terminal */
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		lu = getline(&ligne_tapee, &taille_buffer_getline, stdin);

		if (lu == -1) /* Ctrl+D ou EOF */
		{
			if (isatty(STDIN_FILENO))
				printf("\n"); /* Affiche un \n propre uniquement si interactif */
			free(ligne_tapee);
			exit(0);
		}

		if (ligne_tapee[lu - 1] == '\n')
			ligne_tapee[lu - 1] = '\0';

		if (ligne_tapee[0] != '\0') /* Ignore les lignes vides */
		{
			arguments = tokenize_line(ligne_tapee); /* découpe la ligne */
			if (arguments != NULL)
			{
				execute_commande(arguments); /* exécute la commande */
				for (int i = 0; arguments[i]; i++) /* libère chaque mot */
					free(arguments[i]);
				free(arguments);
			}
		}
	}
	free(ligne_tapee);
}
