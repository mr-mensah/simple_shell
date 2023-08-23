#include "simpleshell.h"
/**
 * myshllexe - function that executes commands
 * @info: arguments
 * Return: null
 */

void myshllexe(info_t *info)
{
char *p = NULL;
int i = 0, path = 0;
while (info->arg[i])
{
path += !shell_lim(info->arg[i], " \t\n") ? 1 : 0;
i++;
}
p = (!path) ? NULL : seeshllpth(info, getshell_env("PATH"), info->argv[0]);
if (p)
{
info->path = p;
executeshell_f(info);
}
else
{
if ((getshell_env("PATH") || info->argv[0][0] == '/')
&& cmdfind(info, info->argv[0]))
executeshell_f(info);
else if (*(info->arg) != '\n')
e_construct(info, "not found\n");
}
}
/**
 * seeshllpth - function that finds path
 * @info: argument
 * @placestr: argument
 * @cmd: command
 * Return: null
 */
char *seeshllpth(info_t *info, char *placestr, char *cmd)
{
int i = 0, post = 0;
char *path;
if (!placestr)
return (NULL);
else if ((stringlength(cmd) > 2) && findcharacter(cmd, "./"))
{
if (cmdfind(info, cmd))
return (cmd);
else
return (NULL);
}
else
{
while (1)
{
if (!placestr[i] || placestr[i] == ':')
{
path = plty_stings(placestr, post, i);
if (!*path)
appendstring(path, cmd);
else
{
appendstring(path, "/");
appendstring(path, cmd);
}
if (cmdfind(info, path))
return (path);
if (!placestr[i])
break;
post = i;
}
i++;
}
return (NULL);
}
}
/**
 * cmdfind - functions that looks for command
 * @info: argument
 * @path: argument
 * Return: null
 */

int cmdfind(info_t *info, char *path)
{
struct stat st;
(void)info;
return ((!path || stat(path, &st)) ? 0 :
(st.st_mode & S_IFREG) ? 1 :
0);
}
/**
 * plty_stings - function that multiplies strings
 * @placestr: argument
 * @beg: argument
 * @end: argument
 * Return: path
 */
char *plty_stings(char *placestr, int beg, int end)
{
static char path[1024];
int p = 0, n = 0;
for (n = 0, p = beg; p < end; p++)
(placestr[p] != ':') ? (path[n++] = placestr[p]) : 0;
path[n] = 0;
return (path);
}
