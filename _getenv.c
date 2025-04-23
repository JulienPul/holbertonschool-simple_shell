#include "main.h"

/**
 * _getenv - Retrieves the value of an environment variable
 * @variable_name: Name of the environment variable to search for
 * Return: Pointer to the value after '=', or NULL if not found
 */

char *_getenv(const char *variable_name)
{
	int index_env = 0;

	while (environ[index_env] != NULL)
	{
		char *env_entry = environ[index_env];

		if (strncmp(env_entry, variable_name, strlen(variable_name)) == 0 && env_entry[strlen(variable_name)] == '=')
		{
			return (env_entry + strlen(variable_name) + 1);
		}
		index_env++;
	}
	return (NULL);
}
