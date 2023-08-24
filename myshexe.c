#include "simpleshell.h"

/**
 * shellexecute - function that executes commands
 * @info: argument
 * Return: null
 */

void shellexecute(info_t *info)
{
	char *p = NULL;
	int r = 0, place = 0;

	while (info->arg[r])
	{
		place += !shel_lim(info->arg[r], " \t\n") ? 1 : 0;
		r++;
	}

	p = (!place) ? NULL : seeshellpath(info, igetshell_env("PATH"), info->argv[0]);

	if (p)
	{
		info->path = p;
		executeshell_fd(info);
	}
	else
	{
	if ((igetshell_env("PATH") || info->argv[0][0] == '/')
			&& commandsearches(info, info->argv[0]))
		executeshell_fd(info);
	else if (*(info->arg) != '\n')
		e_constructer(info, "not found\n");
	}
}

/**
 * seeshellpath - function that finds part in a shell
 * @info: argument
 * @placestr: argument
 * @cmd: command
 * Return: null
 */

char *seeshellpath(info_t *info, char *placestr, char *cmd)
{
	int r = 0, posi = 0;
	char *place;

	if (!placestr)
		return (NULL);
	else if ((mystringlength(cmd) > 2) && findcharacters(cmd, "./"))
	{
		if (commandsearches(info, cmd))
			return (cmd);
		else
			return (NULL);
	}
	else
	{
	while (1)
	{
		if (!placestr[r] || placestr[r] == ':')
		{
			place = mul_strings(placestr, posi, r);
		if (!*place)
			appendstrings(place, cmd);
		else
		{
			appendstrings(place, "/");
			appendstrings(place, cmd);
		}
		if (commandsearches(info, place))
			return (place);
		if (!placestr[r])
			break;
		posi = r;
		}
	r++;
	}
	return (NULL);
	}
}

/**
 * commandsearches - dunction that seraches for a command
 * @info: argument
 * @place: argument
 * Return: place
 */

int commandsearches(info_t *info, char *place)
{
	struct stat st;

	(void)info;
	return ((!place || stat(place, &st)) ? 0 :
		(st.st_mode & S_IFREG) ? 1 :
		0);
}

/**
 * mul_strings - function that multiplies strings
 * @placestr: the directory strings are input
 * @start: string commencement
 * @stop: halting the string
 * Return: final string worked on
 */

char *mul_strings(char *placestr, int start, int stop)
{
	static char place[1024];
	int m = 0, u = 0;

	for (u = 0, m = start; m < stop; m++)
		(placestr[m] != ':') ? (place[u++] = placestr[m]) : 0;
	place[u] = 0;
	return (place);
}

