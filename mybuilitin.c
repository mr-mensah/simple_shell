#include "simpleshell.h"
/**
 * myexitbuiltin_shell - function that writes a custom
 * @info: argument
 * Return: 0
 */
int myexitbuiltin_shell(info_t *info)
{
int i;
if (info->arg != NULL)
{
free(info->arg);
info->arg = NULL;
}
if (info->argv != NULL)
{
for (i = 0; info->argv[i]; i++)
free(info->argv[i]);
free(info->argv);
info->argv = NULL;
}
ssfree(info, 0);
return (0);
}
/**
 * mycustom_env - function that retrieves
 * @info: argument
 * Return: 0
 */
int mycustom_env(info_t *info)
{
char **env;
char *env_entry;
int i;
i = info->argc;
i++;
env = allenv_shell();
if (env != NULL)
{
while (*env != NULL)
{
env_entry = *env;
_printer(env_entry);
_printer("\n");
env++;
}
}
return (0);
}
/**
 * anoldsetenv_shell - function for a variable
 * @info: argument
 * Return: 1
 */

int anoldsetenv_shell(info_t *info)
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
 * anoldunsetenv_shell - function that removes variables
 * @info: argument
 * Return: 1
 */

int anoldunsetenv_shell(info_t *info)
{
if (info->argv[1] != NULL)
{
if (unsetenv(info->argv[1]) == 0)
{
_printer("Env variable unset\n");
return (0);
}
else
{
e_construct(info, "Failed to unset env variable");
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
 * ashell_aliashandler - function that does all
 * @info: argument
 * Return: 1
 */
int ashell_aliashandler(info_t *info)
{
alias_enter alias_table[100];
int num_aliases;
int i;
num_aliases = 0;
if (info->argc < 3)
{
_printer("alias has been set\n");
return (1);
}
if (num_aliases >= OUR_ALIASES)
{
_printer("aliases maximum number reached\n");
return (1);
}
for (i = 0; i < num_aliases; i++)
{
if (stringcompare(info->argv[1], alias_table[i].alias) == 0)
{
copystring(alias_table[i].force, info->argv[2]);
return (0);
}
}
copystring(alias_table[num_aliases].alias, info->argv[1]);
copystring(alias_table[num_aliases].force, info->argv[2]);
num_aliases++;
return (0);
}
