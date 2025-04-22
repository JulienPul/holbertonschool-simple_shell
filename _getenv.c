#include "main.h"

/**
 * _getenv - Récupère la valeur d'une variable d'environnement
 * @nom_variable: Le nom de la variable d'environnement à rechercher
 *
 * Return: Pointeur sur la valeur après '=', ou NULL si non trouvée
 */


/** extern char **environ; : utile pour la fonction, défini dans mon main.h */

char *_getenv(const char *nom_variable)
{
	int index_env = 0;

	while (environ[index_env] != NULL)
	{
		char *ligne_env = environ[index_env];

		if (strncmp(ligne_env, nom_variable, strlen(nom_variable)) == 0 && ligne_env[strlen(nom_variable)] == '=')
		{
			return (ligne_env + strlen(nom_variable) + 1);
		}
		index_env++;
	}
	return (NULL);
}
