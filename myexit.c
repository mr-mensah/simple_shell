#include "simpleshell.h"

/**
 * aafree - function that frees mem
 * @info: argument
 * @exit_status: argument
 * Return: void
 */

void aafree(info_t *info, int exit_status)
{
	if (info != NULL)
	{
		free(info->path);
		free(info->argv);
	}
	exit(exit_status);
}
