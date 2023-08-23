#include "simpleshell.h"
/**
 * dofunction_s - function that does commands
 * @info: argument
 * Return: null
 */
void dofunction_s(info_t *info)
{
pid_t big_pid;
big_pid = fork();
if (big_pid == -1)
{
e_construct(info, "Forking failed");
ssfree(info, 1);
}
if (big_pid == 0)
{
if (execve(info->path, info->argv, allenv_shell()) == -1)
{
switch (errno)
{
case ENOENT:
e_construct(info, "Command not found");
break;
case EACCES:
e_construct(info, "Permission denied");
break;
case EIO:
e_construct(info, "I/O error");
break;
case ENOMEM:
e_construct(info, "Out of memory");
break;
default:
e_construct(info, "Unknown error occurred");
break;
}
ssfree(info, 1);
}
}
else
{
wait(&(info->report));
}
}
