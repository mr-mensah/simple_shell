#include "simpleshell.h"

/**
 * shellloopmain - sunction that does the loop
 * @explainer: explains
 * @argc: argument
 * @argv: argument
 * @line: line
 * @line_length: length
 * @file: file
 * @info: argument
 * @built_in_ret: argument
 * Return: 0
 */

int shellloopmain(int explainer, int argc, char **argv, char *line,
		size_t line_length, ownership file, info_t info,
		int built_in_ret)
{
	while (1)
	{
		info.show++;
		if (file.explainer != 0 && file.show_flag == 0)
			amimic_buffile(file, line, line_length);
		else
		{
			if (isatty(STDIN_FILENO))
				ishell_printer();
			fflush(stdout);
		if (mybufferfile_handler(&line, &line_length, 0) == -1)
			{
				if (explainer != 0)
					close(explainer);
				return (0);
			}
			init_builtin(&info, argc, argv, line);
			if (line_length > 0)
			{
				built_in_ret = wefindbuiltin_shell(&info);
				if (built_in_ret == -2)
					break;
				else if (built_in_ret == -1)
				{
					info.path = info.argv[0];
					shellexecute(&info);
				}
			}
		}
		ashell_freedom(&info, line);
	}
	if (explainer != 0)
		close(explainer);
	return (0);
}

/**
 * amimic_buffile - function that reads a file
 * @file: argument
 * @line: argument
 * @line_length: length
 * Return: null
 */

void amimic_buffile(ownership file, char *line, size_t line_length)
{
while (mybufferfile_handler(&line, &line_length, file.explainer) != -1)
	{
		if (line_length > 0)
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
 * init_builtin - functionthat performs initialization
 * @info: argument
 * @argc: argument
 * @argv: argument
 * @line:  argument
 * Return: null
 */

void init_builtin(info_t *info, int argc, char **argv, char *line)
{
			info->path = line;
			info->argv = NULL;
			info->pipefd[0] = -1;
			info->pipefd[1] = -1;
			info->report = -1;
			info->lrf_fd = -1;
			info->argc = argc;
			info->arg = stringduplicates(line);
			info->argv = NULL;
			info->shell = argv[0];
			destringsplit(info);
}

/**
 * ashell_freedom - function that frees space
 * @info: argument
 * @line: argument
 * Return: null
 */

void ashell_freedom(info_t *info, char *line)
{
	int i;

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
			for (i = 0; info->argv[i]; i++)
				free(info->argv[i]);
			free(info->argv);
			info->argv = NULL;
		}
}

