#include "holberton.h"

/**
 * @ex_st: exit status to print the exit status
 * @env: the environment variable to print the environment
 * printenv - prints the environment variable that we use 
 * Return:  (0) if success Always
 */
int printenv(char **env, int *ex_st)
{
	unsigned int l = 0;
	while (env[l] != NULL)
	{
		print_str(env[l]);
		_putchar('\n');
		l++;
	}*ex_st = 0;
	return (EXIT_SUCCESS);
}
