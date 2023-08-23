#include "simpleshell.h"
/**
 * wordssep - functions that seperates
 * @info: argument
 * Return: j
 */
int wordssep(info_t *info)
{
int j;
(*info).argv = copy_stkk((*info).arg, " \t");
if (!(*info).argv)
{
(*info).argv = malloc(sizeof(char *) * 2);
if ((*info).argv)
{
(*info).argv[0] = stringduplicate((*info).arg);
(*info).argv[1] = NULL;
}
}
for (j = 0; (*info).argv && (*info).argv[j]; j++)
;
(*info).argc = j;
return (j);
}
/**
 * copy_stkk - copies the behaviour of a library
 * @abc: strings
 * @del: argument
 * Return: solution
 */
char **copy_stkk(char *abc, char *del)
{
int s1, s2, s3, s4, nonWrds = 0;
char **solution;
int j;
if (abc == NULL || abc[0] == 0)
return (NULL);
if (!del)
del = " ";
for (s1 = 0; abc[s1] != '\0'; s1++)
if (!shl_dlm(abc[s1], del)
&& (shl_dlm(abc[s1 + 1], del)
|| !abc[s1 + 1]))
nonWrds++;
if (nonWrds == 0)
return (NULL);
solution = malloc((1 + nonWrds) *sizeof(char *));
if (!solution)
return (NULL);
for (s2 = 0, s3 = 0; s3 < nonWrds; s3++)
{
while (shl_dlm(abc[s2], del))
s2++;
s4 = 0;
while (!shl_dlm(abc[s2 + s4], del)
&& abc[s2 + s4])
s4++;
solution[s3] = malloc((s4 + 1) * sizeof(char));
if (!solution[s3])
{
for (s4 = 0; s4 < s3; s4++)
free(solution[s4]);
free(solution);
return (NULL);
}
for (j = 0; j < s4; j++)
solution[s3][j] = abc[s2++];
solution[s3][s4] = 0;
}
solution[s3] = NULL;
return (solution);
}
/**
 * shl_dlm - function that checks for delimeter
 * @c: character
 * @del: argument
 * Return: 0
 */
int shl_dlm(char c, char *del)
{
int j = 0;
while (del[j] != '\0')
{
if (del[j] == c)
return (1);
j++;
}
return (0);
}
