#include "holberton.h"

/**
 * @s: the string
 * _strlen - gives len of a string 
 * Return: returns len of  the string
 */
int _strlen(char *s)
{
	int l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}
/**
 * _strcmp - compares two strings with each other
 * @s1: str 1
 * @s2: str 2
 * Return: comparison of two strings with each other
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcpy - copies string and put it to another string
 * @dest: str 1
 * @src: str 2
 * Return: copy of this string
 */
char *_strcpy(char *dest, char *src)
{
	int y;
	for (y = 0; y <= _strlen(src); y++)
		dest[y] = src[y];
	return (dest);
}

/**
 * @str: - Char to be copied string
 * _strdup - function that returns a pointer to a newly allocated space in the 	
 * memory, which contains a copy of the string given as a parameter from user
 * Return: Char pointer to the duplicated string. and Return NULL if insufficient 
 * memory was available to array or if array is NULL
 */

char *_strdup(char *str)
{
	char *dup;
	int i, l;
	if (str == NULL)
		return (NULL);
	l = 0;
	for (i = 0; str[i] != '\0'; i++)
		l++;
	dup = malloc(sizeof(char) * l + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < l ; i++)
		dup[i] = str[i];
	dup[l] = '\0';
	return (dup);
}


/**
 * @dest: 1 str
 * @src: 2 str
 * _strcat - concatenat two strings with each other
 * Return: concatenated string with overwritten 
 */
char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int i;
	for (i = 0; src[i] != '\0'; i++)
		dest[len + i] = src[i];
	dest[len + i] = '\0';

	return (dest);
}
