#include "simpleshell.h"

/**
 * igetshell_env - function that calls the environment
 * @variable: argument
 * Return: null
 */

char *igetshell_env(const char *variable)
{

	size_t var_length;
	char **env = environ;

	if (variable == NULL)
	{
		return (NULL);
	}

	var_length = mystringlength(variable);

	while (*env != NULL)
	{
	if (stringcompare_num(variable, *env, var_length) == 0
		&& (*env)[var_length] == '=')
	{
		return (&((*env)[var_length + 1]));
	}
	env++;
	}

	return (NULL);
}

