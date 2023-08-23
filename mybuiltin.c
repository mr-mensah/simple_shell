#include "simpleshell.h"
/**
 * myshell_bullt - function that handles changing the work env
 * @info: argument in the struct
 * Return: 1 when changed successfully and 0 on failure
 */

int myshell_bullt(info_t *info)
{
char *a, *pat, buffer[1024];
int chdir_ret;
a = getcwd(buffer, 1024);
if (!a)
{
perror("getcwd failure");
return (1);
}
if (!info->argv[1])
{
pat = getshell_env("HOME");
if (!pat)
chdir_ret = chdir((pat = getshell_env("PWD")) ? pat : "/");
else
chdir_ret = chdir(pat);
}
else if (stringcompare(info->argv[1], "-") == 0)
{
if (!getshell_env("OLDPWD"))
{
_printer(a);
_printer("\n");
return (1);
}
_printer(getshell_env("OLDPWD"));
_printer("\n");
chdir_ret = chdir((pat = getshell_env("OLDPWD")) ? pat : "/");
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
 * fillmeme_shll - function that puts in memory
 * @a: char
 * @b: char
 * @n: int
 * Return: a
 */
char *fillmeme_shll(char *a, char b, unsigned int n)
{
unsigned int j;
for (j = 0; j < n; j++)
{
*(a + j) = b;
}
return (a);
}
