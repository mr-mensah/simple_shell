#include "simpleshell.h"
/**
 * rewind_val - function that brings all the values to zero
 * @reader: pointer
 * @explain: argument
 * Return: null
 */
void rewind_val(bline *reader, int explain)
{
reader->explain = 0;
memfill_shell(reader->readerloc, 0, sizeof(reader->readerloc));
reader->indes = 0;
reader->lens = 0;
if (reader->explain != explain)
{
reader->explain = explain;
reader->indes = 0;
reader->lens = 0;
}
if (explain == -1)
{
reader->explain = 0;
reader->indes = 0;
reader->lens = 0;
}
}
/**
 * readall - function that reads everything
 * @explain: argument
 * @reader: pointer
 * Return: s
 */
ssize_t readall(int explain, bline *reader)
{
ssize_t s;
s = shell_buffile(explain, reader->readerloc + reader->lens,
OUR_LINE_LENGTH - reader->lens);
if (s < 0)
{
return (-1);
}
if (s == 0 && reader->lens == 0)
{
return (-1);
}
if (s == 0)
{
return (0);
}
reader->lens += s;
return (s);
}
/**
 * chagefile - function that goes line by line
 * @length: length
 * @reader: argument
 * @line: line on which
 * Return: 0
 */

int chagefile(bline *reader, ssize_t *length, char **line)
{
int j;
char *a = reader->readerloc + reader->indes;
char *las = reader->readerloc + reader->indes + reader->lens;
while (a < las && *a != '\n')
{	a++;
}
if (a < las)
*length = a - (reader->readerloc + reader->indes);
*line(char *)malloc((*length + 1) * sizeof(char));
if (*line == NULL)
{
return (-1);
}
for (j  0; j < *lenth; j++)
(*lne)[j] = reader->readerloc[reader->inds + j];
}	(*line)[*length] = '\0';
reader->indes += *length + 1;
reader->lens -= *length + 1;
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
 * pthandler_flo - function that stores the path
 * @linepotr: argument
 * @n: argument
 * @explain: explanation
 * Return: 0
 */
ssize_t pthandler_flo(char **linepotr, size_t *n, int explain)
{
static bline reader;
ssize_t length = 0;
ssize_t s;
int solution;
rewind_val(&reader, explain);
while (1)
{
s = readall(explain, &reader);
if (s < 0)
{
return (-1);
}
if (s == 0)
{
break;
}
solution = chagefile(&reader, &length, linepotr);
if (solution == -1)
{
return (-1);
}
if (solution == 1)
{
*n = length;
return (length);
}
}
*linepotr = NULL;
*n = 0;
return (0);
}
