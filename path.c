#include "holberton.h"
/**
 *  @ex_st: the exit status
 * @env: environment variable to use the environment
 * @input: the tokenized arguments we use
 * @first: the first tokenized keyword we use
 * _path - it is a function that prints environment PATH 
 * Return: 0 if command is found and executed
 */
int _path(char *first, char **input, char **env, int *ex_st)
{
	int l;
	char *temp, *left, *right;
	char *new = NULL, *envcopy = NULL;

	for (l = 0; env[l] != '\0'; l++)
	{
		envcopy = _strdup(env[l]);
		left = strtok(envcopy, "= \t");
		temp = strtok(NULL, "= \t");
		if (_strcmp(left, "PATH") == 0)
		{
			right = strtok(temp, ": \t");
			while (right)
			{
				new = pathstr(right, first);
				if (access(new, X_OK) == 0)
				{
					if (fork() == 0)
						execve(new, input, NULL);
					else
						wait(NULL);
					*ex_st = 0;
					free(new);
					free(envcopy);
					return (0);
				}right = strtok(NULL, ": \t");
				free(new);
			}
		}free(envcopy);
	}return (2);
}
