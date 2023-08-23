#include "simpleshell.h"
/**
 * digshll_ev - gets value of an environment var
 * @var: name of the environment var
 * Return: value of the environment var
 */
char *digshll_ev(const char *var)
{
size_t var_length;
char **env = environ;
if (var == NULL)
{
return (NULL);
}
var_length = stringlength(var);
while (*env != NULL)
{
if (stringcompare_n(var, *env, var_length) == 0
&& (*env)[var_length] == '=')
{
return (&((*env)[var_length + 1]));
}
env++;
}
return (NULL);
}
