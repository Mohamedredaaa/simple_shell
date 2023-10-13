#include "holberton.h"

/**
 * @line: the buffer we use
 * @args: the parsed arguments in the shell
 * @env: the environment thet we use
 * @ex_st: to exit status 
 * builtins - it is a function that implements the exit and printenv for us 
 * Return: void 
 */
void builtins(char *line, char **args, char **env, int *ex_st)
{

	if (_strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(*ex_st);
	}if (_strcmp(args[0], "env") == 0)
		printenv(env, ex_st);
}
