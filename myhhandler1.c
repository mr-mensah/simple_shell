#include "simpleshell.h"
/**
 * wordlong - function that looks at the length
 * @str: argument
 * Return: length
 */
int wordlong(const char *str)
{
int length;
length = 0;
if (!str)
{
return (0);
}
while (*str != '\0')
{
length = length + 1;
str = str + 1;
}
return (length);
}
/**
 * wordtoword - function that does comparison
 * @str1: string number one
 * @str2: string number 2
 * Return: 1
 */
int wordtoword(char *str1, char *str2)
{
int j;
j = 0;
while (str1[j] != '\0' && str2[j] != '\0')
{
if (str1[j] != str2[j])
{
return (-1);
}
j++;
}
if (str1[j] == '\0' && str2[j] == '\0')
{
return (0);
}
else
{
return (1);
}
}
/**
 * searchlett - function that finds a string
 * @str: argument
 * @character: character
 * Return: result
 */

char *searchlett(char *str, char *character)
{
int len_string, leng_char;
char *result;
int j;
len_string = 0;
leng_char = 0;
while (*(character + leng_char) != '\0')
leng_char++;
while (*(str + len_string) != '\0')
len_string++;
for (j = 0; j < leng_char; j++)
{
if (*(character + j) != *(str + j))
{
return ((char *)NULL);
}
}
result = (char *)str;
return (result);
}
/**
 * sendlett - function that catches strings
 * @dest: destinations
 * @src: src
 * Return: dest
 */

char *sendlett(char *dest, const char *src)
{
int dest_len;
int j;
int src_len;
dest_len = 0;
src_len = 0;
while (dest[dest_len] != '\0')
{
dest_len++;
}
while (src[src_len] != '\0')
{
src_len++;
}
for (j = 0; j < src_len; j++)
{
dest[dest_len + j] = src[j];
}
dest[dest_len + j] = '\0';
return (dest);
}
/**
 * duplicateword- function that duplicates string
 * @dests: destinations
 * @sources: argument
 * Return: dests
 */

char *duplicateword(char *dests, char *sources)
{
int j;
j = 0;
if (dests == sources || sources == 0)
{
return (dests);
}
while (sources[j] != '\0')
{
dests[j] = sources[j];
j++;
}
dests[j] = '\0';
return (dests);
}
