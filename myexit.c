#include "simpleshell.h"
/**
 * fremmm - frees memory allocated in the struct
 * @info: struct parameter argument
 * @out_stats: represents the exit status
 * Return: void
 */
void fremmm(info_t *info, int out_stats)
{
if (info != NULL)
{
free(info->path);
free(info->argv);
}
exit(out_stats);
}
