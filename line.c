#include "simpleshell.h"

/**
 * myreset_structure - function that resets
 * @reader: argument
 * @explainer: argument
 * Return: null
 */

void myreset_structure(bline *reader, int explainer)
{
	reader->explainer = 0;
	memfill_shela(reader->readerloc, 0, sizeof(reader->readerloc));
	reader->indes = 0;
	reader->lens = 0;

	if (reader->explainer != explainer)
	{
		reader->explainer = explainer;
		reader->indes = 0;
		reader->lens = 0;
	}

	if (explainer == -1)
	{
		reader->explainer = 0;
		reader->indes = 0;
		reader->lens = 0;
	}
}

/**
 * afilereader - function that reads everything
 * @explainer: argument
 * @reader: argument
 * Return: r
 */

ssize_t afilereader(int explainer, bline *reader)
{
	ssize_t r;

	r = shel_bunffile(explainer, reader->readerloc + reader->lens,
		OUR_LINE_LENGTH - reader->lens);
	if (r < 0)
	{
		return (-1);
	}
	if (r == 0 && reader->lens == 0)
	{
		return (-1);
	}
	if (r == 0)
	{
		return (0);
	}
	reader->lens += r;
	return (r);
}

/**
 * afileplacereader - function that reads thelines
 * @line_length: argument
 * @reader: argument
 * @line: argunment
 * Return: 1
 */

int afileplacereader(bline *reader, ssize_t *line_length, char **line)
{
	int i;
	char *p = reader->readerloc + reader->indes;
	char *end = reader->readerloc + reader->indes + reader->lens;

	while (p < end && *p != '\n')
	{
		p++;
	}

	if (p < end)
	{
	*line_length = p - (reader->readerloc + reader->indes);
	*line = (char *)malloc((*line_length + 1) * sizeof(char));
	if (*line == NULL)
	{
		return (-1);
	}
	for (i = 0; i < *line_length; i++)
	{
		(*line)[i] = reader->readerloc[reader->indes + i];
	}
	(*line)[*line_length] = '\0';
	reader->indes += *line_length + 1;
	reader->lens -= *line_length + 1;
	if (reader->lens == 0)
	{
		reader->indes = 0;
	}
	return (1);
	}

	if (reader->lens == OUR_LINE_LENGTH)
	{
		reader->indes = 0;
		reader->lens = 0;
	}
	return (0);
}
/**
 * mybufferfile_handler - function that reads the lines
 * @lineptr: argument
 * @n: points to the whole things
 * @explainer: argument
 * Return: 0
 */


ssize_t mybufferfile_handler(char **lineptr, size_t *n, int explainer)
{
	static bline reader;
	ssize_t line_length = 0;
	ssize_t r;
	int result;

	myreset_structure(&reader, explainer);

	while (1)
	{
		r = afilereader(explainer, &reader);
		if (r < 0)
		{
		return (-1);
		}
		if (r == 0)
		{
			break;
		}
		result = afileplacereader(&reader, &line_length, lineptr);
		if (result == -1)
		{
			return (-1);
		}
		if (result == 1)
		{
			*n = line_length;
			return (line_length);
		}
	}

	*lineptr = NULL;
	*n = 0;
	return (0);
}

