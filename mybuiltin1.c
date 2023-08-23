#include "simpleshell.h"
/**
 * searchinbuilt_shll - function that does commands
 * @info: argument
 * Return: 1
 */
int searchinbuilt_shll(info_t *info)
{
int j, in_built_ret = -1;
builtin_board builtintbl[] = {
{"exit", exitbuiltin_shell},
{"env", custom_env},
{"cd", shell_builtincd},
{"setenv", oldsetenv_shell},
{"unsetenv", oldunsetenv_shell},
{"alias", oldunsetenv_shell},
{NULL, NULL}
};
for (j = 0; builtintbl[j].type; j++)
{
if (stringcompare(info->argv[0], builtintbl[j].type) == 0)
{
in_built_ret = builtintbl[j].func(info);
break;
}
}
return (in_built_ret);
}
