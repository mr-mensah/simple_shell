#include "simpleshell.h"
/**
 * shll_shuff - a function to go through and store
 * @explanation: argument
 * @shuffler: pointer
 * @length: length
 *
 * Return: all_red
 */

ssize_t shll_shuff(int explanation, char *shuffler, ssize_t length)
{
ssize_t all_red;
ssize_t bts_rd;
char ab;
bts_rd = 0;
all_red = 0;
while (all_red < length - 1)
{
bts_rd = read(explanation, &ab, 1);
if (bts_rd == -1)
{
return (-1);
}
else if (bts_rd == 0)
{
break;
}
else
{
shuffler[all_red] = ab;
all_red++;
if (ab == '\n')
{
break;
}
}
}
shuffler[all_red] = '\0';
return (all_red);
}
/**
 * skim_shll - function that goes through everything
 * @explanation: argument
 * @shuffler: pointer
 * Return: all_red
 */
ssize_t skim_shll(int explanation, char **shuffler)
{
off_t fol_sze;
ssize_t shuffer_size;
ssize_t all_red;
fol_sze = bring_out(explanation, 0, SEEK_END);
if (fol_sze == -1)
{
return (-1);
}
shuffer_size = fol_sze + 1;
*shuffler = (char *)malloc(shuffer_size *sizeof(char));
if (*shuffler == NULL)
{
return (-1);
}
bring_out(explanation, 0, SEEK_SET);
all_red = read(explanation, *shuffler, shuffer_size - 1);
if (all_red == -1)
{
free(*shuffler);
return (-1);
}
(*shuffler)[all_red] = '\0';
return (all_red);
}
/**
 * bring_out - function to bring out
 * @explanation: argument
 * @offset: offset
 * @hence:  argument
 * Return: end_offset
 */
off_t bring_out(int explanation, off_t offset, int hence)
{
off_t begin_offset;
off_t end_offset;
off_t fol_sze;
begin_offset = bring_out(explanation, 0, SEEK_CUR);
end_offset = begin_offset;
if (hence == SEEK_SET)
{
end_offset = offset;
}
else if (hence == SEEK_CUR)
{
end_offset = begin_offset + offset;
}
else if (hence == SEEK_END)
{
fol_sze = bring_out(explanation, 0, SEEK_END);
end_offset = fol_sze + offset;
}
bring_out(explanation, end_offset, SEEK_SET);
return (end_offset);
}
/**
 * copy_bring - copies the behaviour of the function
 * @stream: argument
 * Return: 1 or else 0
 */
int copy_bring(FILE *stream)
{
if (stream == stdout)
{
file_writer('\n', stream);
return (0);
}
else
{
return (EOF);
}
}
