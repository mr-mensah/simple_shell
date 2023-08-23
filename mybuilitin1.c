#include "simpleshell.h"
/**
 * ashell_builtincd - function that brings the environment
 * @info: argument
 * Return: 1
 */
int ashell_builtincd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;
s = getcwd(buffer, 1024);
if (!s)
{
perror("getcwd failure");
return (1);
}
if (!info->argv[1])
{
dir = getshell_env("HOME");
if (!dir)
chdir_ret = chdir((dir = getshell_env("PWD")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (stringcompare(info->argv[1], "-") == 0)
{
if (!getshell_env("OLDPWD"))
{
_printer(s);
_printer("\n");
return (1);
}
_printer(getshell_env("OLDPWD"));
_printer("\n");
chdir_ret = chdir((dir = getshell_env("OLDPWD")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
e_construct(info, "can't cd to ");
write(2, info->argv[1], stringlength(info->argv[1]));
write(2, "\n", 2);
}
else
setenv("OLDPWD", getshell_env("PWD"), 1);
return (0);
}
/**
 * memfill_shela - a functions that fills a memory
 * @s: pointer
 * @b: argument
 * @n: argument
 * Return: s
 */
char *memfill_shela(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
{
*(s + i) = b;
}
return (s);
}
