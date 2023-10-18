#include "shell.h"


/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * This function takes a string 's' and attempts to convert it into an integer. If there
 * are no valid numbers in the string, it returns 0. Otherwise, it returns the converted
 * number.
 *
 * Return: 0 if there are no numbers in the string, the converted number otherwise.
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}


/**
 * interactive - Determines whether the shell is in interactive mode.
 * @info: A pointer to the information struct.
 * This function checks whether the shell is operating in interactive mode based on the
 * provided information. It returns 1 if the shell is in interactive mode, and 0 otherwise.
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - Checks whether a character is a delimiter based on a delimiter string.
 * @c: The character to check.
 * @delim: The delimiter string for comparison.
 * This function examines if the character 'c' is a delimiter, as defined by the 'delim' string.
 * It returns 1 if 'c' is a delimiter according to the provided 'delim,' and 0 otherwise.
 *
 * Return: 1 if 'c' is a delimiter, 0 if it's not.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}


/**
 * _isalpha - Checks whether a character is alphabetic.
 * @c: The character to check.
 *
 * This function determines if the character 'c' is an alphabetic character (a-z or A-Z).
 * It returns 1 if 'c' is an alphabetic character and 0 otherwise.
 *
 * Return: 1 if 'c' is alphabetic, 0 if it's not.
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
 


