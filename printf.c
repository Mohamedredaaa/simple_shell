#include "holberton.h"

/**
 * @c: it is The char to print
 * _putchar - writes the character c to stdout
 * Return: 1 On success . 0 On error, -1 is returned..
 */
int _putchar(char c)
{return (write(1, &c, 1));}

/**
 * @s: TO PRINT THE STRING
 * print_str - that prints a string
 * Return: it is void
 */
void print_str(char *s)
{
	int i, bytes, wc;

	for (i = 0; s[i] != '\0'; i++)
		;

	bytes = i;
	wc = write(STDOUT_FILENO, s, bytes);
	if (wc == EOF)
		return;
}


/**
 * @first: FIRST TOKENIZED KEYWORD
 * @right: string after "PATH ="
 * pathstr - it is a function that print the path for string
 * Return: 0 if command is found and executed
 */
char *pathstr(char *right, char *first)
{
	char *new = NULL;
	char *token = NULL;
	int token_len = 0, first_len = 0;
	token = right;
	token_len = _strlen(token);
	first_len = _strlen(first);
	new = malloc((token_len + first_len + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);

	new[0] = '\0';
	_strcat(new, right);
	_strcat(new, "/");
	_strcat(new, first);
	_strcat(new, "\0");
	return (new);
}

/**
 * @tally: pointer to tally number
 * print_int -that print an int
 * Return: VOID
 */
void print_int(int *tally)
{
	int count = 0, length = 0, S, M;
	unsigned int base = 1, H, max;
	M = *tally;
	max = M;
	H = max;
	do {
		H /= 10;
		++length;
	} while (H != 0);
	count += length;
	for (S = 0; S < length -  1; S++)
		base = base * 10;
	_putchar('0' + (max / base));
	if (length > 1)
	{
		for (S = 0; S < length - 2; S++)
		{
			base /= 10;
			H = max / base;
			_putchar('0' + H % 10);
		}
		_putchar('0' + (max % 10));
	}
}


/** 
 * @l: Char pointer for storing user input and info
 * parser - it is a function that takes a string from the command line and returns the
 * Return: Char double pointer comprised of a char pointer that each contain and the same an argument
 */

char **parser(char *l)
{
	char **args;
	char *parsed = NULL;
	char *parsed2 = NULL;
	char *linecopy = NULL;
	int arg_num = 0, i = 0;
	linecopy = _strdup(l);
	parsed = strtok(linecopy, " \t");

	while (parsed != NULL)
	{
		arg_num++;
		parsed = strtok(NULL, " \t");
	}
	args = malloc(sizeof(char *) * (arg_num + 1));
	if (args == NULL)
		return (NULL);

	parsed2 = strtok(l, " \t");
	while (parsed2 != NULL)
	{
		args[i] = parsed2;
		parsed2 = strtok(NULL, " \t");
		i++;
	}
	args[i] = NULL;
	free(linecopy);
	return (args);
}
