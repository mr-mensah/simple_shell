#include "simpleshell.h"
/**
 * myshell_exit - function that makes exit for shell
 * @info: argument
 * Return: 0
 */
int myshell_exit(info_t *info)
{
int j;
if (info->arg != NULL)
{
free(info->arg);
info->arg = NULL;
}
if (info->argv != NULL)
{
for (j = 0; info->argv[j]; j++)
free(info->argv[j]);
free(info->argv);
info->argv = NULL;
}
ssfree(info, 0);
return (0);
}
/**
 * mycomp_env - function that creates environment
 * @info: argument
 * Return: 0
 */
int mycomp_env(info_t *info)
{
char **env;
char *env_inside;
int j;
j = info->argc;
j++;
env = allenv_shell();
if (env != NULL)
{
while (*env != NULL)
{
env_inside = *env;
_printer(env_inside);
_printer("\n");
env++;
}
}
return (0);
}
/**
 * comeset_env - function that sets the environment
 * @info: argument
 * Return: 1
 */
int comeset_env(info_t *info)
{
if (info->argv[1] != NULL && info->argv[2] != NULL)
{
if (setenv(info->argv[1], info->argv[2], 1) == 0)
{
_printer("Env variable set successfully\n");
return (0);
}
else
{
e_construct(info, "Failed to set env variable");
return (1);
}
}
else
{
e_construct(info, "Argument number invalid");
return (1);
}
}
/**
 * alreadset_env - function that removes environment
 * @info: argument
 * Return: 1
 */

int alreadset_env(info_t *info)
{
if (info->argv[1] != NULL)
{
if (unsetenv(info->argv[1]) == 0)
{
_printer("Environment variable unset\n");
return (0);
}
else
{
e_construct(info, "Failed to unset environment variable");
return (1);
}
}
else
{
e_construct(info, "Arg number invalid");
return (1);
}
}
/**
 * shll_ali - function that sets the aliases
 * @info: argument
 * Return: 1
 */
int shll_ali(info_t *info)
{
alias_enter alias_table[100];
int num_aliss;
int j;
num_aliss = 0;
if (info->argc < 3)
{
_printer("Alias have been set\n");
return (1);
}
if (num_aliss >= OUR_ALIASES)
{
_printer("Aliases highest num reached\n");
return (1);
}
for (j = 0; j < num_aliss; j++)
{
if (stringcompare(info->argv[1], alias_table[j].alias) == 0)
{
copystring(alias_table[j].force, info->argv[2]);
return (0);
}
}
copystring(alias_table[num_aliss].alias, info->argv[1]);
copystring(alias_table[num_aliss].force, info->argv[2]);
num_aliss++;
return (0);
}
