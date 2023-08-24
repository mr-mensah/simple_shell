#include "simpleshell.h"

/**
 * executeshell_fd - function that executes files
 * @info: argument
 * Return: null
 */

void executeshell_fd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		e_constructer(info, "Fork failed");
		aafree(info, 1);
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, allenv_dshell()) == -1)
		{
		switch (errno)
		{
			case ENOENT:
				e_constructer(info, "Command not found");
				break;
			case EACCES:
				e_constructer(info, "Permission denied");
				break;
			case EIO:
				e_constructer(info, "I/O error");
				break;
			case ENOMEM:
				e_constructer(info, "Out of memory");
				break;
			default:
				e_constructer(info, "Unknown error occurred");
				break;
		}
		aafree(info, 1);
	}
	}
	else
	{
		wait(&(info->report));
	}
}

