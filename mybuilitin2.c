#include "simpleshell.h"

/**
 * wefindbuiltin_shell - function that does it
 * @info: argument
 * Return: 1
 */

int wefindbuiltin_shell(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_board builtintbl[] = {
		{"exit", myexitbuiltin_shell},
		{"env", mycustom_env},
		{"cd", ashell_builtincd},
		{"setenv", anoldsetenv_shell},
		{"unsetenv", anoldunsetenv_shell},
		{"alias", anoldunsetenv_shell},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
	{
		if (astringcompare(info->argv[0], builtintbl[i].type) == 0)
		{
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	}

	return (built_in_ret);
}

