#include "simpleshell.h"
/**
 * shel_bunffile - function to shuffle
 * @explainer: argument
 * @buffer: argument
 * @max_length: argument
 * Return: total
 */
ssize_t shel_bunffile(int explainer, char *buffer, ssize_t max_length)
{
ssize_t total_read;
ssize_t bytes_read;
char ch;
bytes_read = 0;
total_read = 0;
while (total_read < max_length - 1)
{
bytes_read = read(explainer, &ch, 1);
if (bytes_read == -1)
{
return (-1);
}
else if (bytes_read == 0)
{
break;
}
else
{
buffer[total_read] = ch;
total_read++;
if (ch == '\n')
{
break;
}
}
}
buffer[total_read] = '\0';
return (total_read);
}
/**
 * readers_shel - reads and depicts
 * @explainer: argument
 * @buffer: argument
 * Return: total
 */
ssize_t readers_shel(int explainer, char **buffer)
{
off_t file_size;
ssize_t buffer_size;
ssize_t total_read;
file_size = myflush_file(explainer, 0, SEEK_END);
if (file_size == -1)
{
return (-1);
}
buffer_size = file_size + 1;
*buffer = (char *)malloc(buffer_size *sizeof(char));
if (*buffer == NULL)
{
return (-1);
}
myflush_file(explainer, 0, SEEK_SET);
total_read = read(explainer, *buffer, buffer_size - 1);
if (total_read == -1)
{
free(*buffer);
return (-1);
}
(*buffer)[total_read] = '\0';
return (total_read);
}
/**
 * myflush_file - function that hollows
 * @explainer:  argument
 * @offset: argument
 * @whence: argument
 * Return: argument
 */
off_t myflush_file(int explainer, off_t offset, int whence)
{
off_t current_offset;
off_t new_offset;
off_t file_size;
current_offset = myflush_file(explainer, 0, SEEK_CUR);
new_offset = current_offset;
if (whence == SEEK_SET)
{
new_offset = offset;
}
else if (whence == SEEK_CUR)
{
new_offset = current_offset + offset;
}
else if (whence == SEEK_END)
{
file_size = myflush_file(explainer, 0, SEEK_END);
new_offset = file_size + offset;
}
myflush_file(explainer, new_offset, SEEK_SET);
return (new_offset);
}
/**
 * mimc_flush - copies the behaviour of the flas
 * @stream: argument
 * Return: argument
 */
int mimc_flush(FILE *stream)
{
if (stream == stdout)
{
file_writers('\n', stream);
return (0);
}
else
{
return (EOF);
}
}
