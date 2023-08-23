#include "simpleshell.h"
/**
 * myloopy - function that makes the shell loop
 * @explainer: argument
 * @argc: argument
 * @argv: argument
 * @line: argument
 * @length: argument
 * @file: argument
 * @info: argument
 * @built_in_ret: argument
 * Return: 0
 */
int myloopy(int explainer, int argc, char **argv, char *line,
size_t length, ownership file, info_t info,
int built_in_ret)
{
while (1)
{
info.show++;
if (file.explainer != 0 && file.show_flag == 0)
copy_shuff(file, line, length);
else
{
if (isatty(STDIN_FILENO))
shell_printer();
fflush(stdout);
if (bufferfile_handler(&line, &length, 0) == -1)
{
if (explainer != 0)
close(explainer);
return (0);
}
start_bill(&info, argc, argv, line);
if (length > 0)
{
built_in_ret = findbuiltin_shell(&info);
if (built_in_ret == -2)
break;
else if (built_in_ret == -1)
{
info.path = info.argv[0];
shellexec(&info);
}
}
}
shll_move(&info, line);
}
if (explainer != 0)
close(explainer);
return (0);
}
/**
 * copy_shuff - functions that reads lines
 * @file: argument
 * @line: argument
 * @length: length
 * Return: null
 */
void copy_shuff(ownership file, char *line, size_t length)
{
while (bufferfile_handler(&line, &length, file.explainer) != -1)
{
if (length > 0)
{
free(line);
}
else
{
break;
}
}
file.show_flag = 1;
}
/**
 * start_bill - function that starts everything
 * @info: argument
 * @argc: argument
 * @argv: argument
 * @line:  argument
 * Return: null
 */
void start_bill(info_t *info, int argc, char **argv, char *line)
{
info->path = line;
info->argv = NULL;
info->pipefd[0] = -1;
info->pipefd[1] = -1;
info->report = -1;
info->lrf_fd = -1;
info->argc = argc;
info->arg = stringduplicate(line);
info->argv = NULL;
info->shell = argv[0];
stringsplit(info);
}
/**
 * shll_move - function that deletes every memory
 * @info: argument
 * @line: argument
 * Return: null
 */
void shll_move(info_t *info, char *line)
{
int j;
if (line != NULL)
{
free(line);
line = NULL;
}
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
}
