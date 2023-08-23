#include "simpleshell.h"
/**
 * wordsconding - function that can copy string
 * @str: argument
 * Return: null
 */
char *wordsconding(char *str)
{
int len = 0;
char *end;
if (str == NULL)
return (NULL);
while (*str++)
len++;
end = malloc(sizeof(char) * (len + 1));
if (!end)
return (NULL);
for (len++; len--;)
end[len] = *--str;
return (end);
}
/**
 * wordandwrd_o - function that compares
 * @str1: first string
 * @str2: second string
 * @n: argument
 * Return: 0
 */

int wordandwrd_o(const char *str1, const char *str2, size_t n)
{
size_t j;
j = 0;
while (j < n)
{
if (str1[j] != str2[j])
{
return (str1[j] - str2[j]);
}
if (str1[j] == '\0')
{
return (0);
}
j++;
}
return (0);
}
/**
 * myfile_send - function that checks everything
 * @c: argument
 * @stream: pointe
 * Return: null
 */
void myfile_send(char c, FILE *stream)
{
if (stream == stdout || stream == stderr)
{
write(fileno(stream), &c, 1);
}
}
