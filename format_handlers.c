#include "main.h"

/**
 * format_handler - Handles format specifiers
 * @ch: Character that determines the how to handle the variable argument
 * @va_list: The variable argument to format and print
 *
 * Return: The number of characters printed to stdout
 */
int format_handler(va_list vargs, char fchar)
{
	if (fchar == 's')
		return (print_string(va_arg(vargs, char *)));
	else if (fchar == 'c')
		return (print_char(va_arg(vargs, int)));
	else if (fchar == '%')
		return (print_char('%'));
	else
		return (-1);
}

/**
 * _strlen - Calculates the length of a string
 * @str: String of which its length will be calculated
 *
 * Return: The length of str
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * print_string - Prints a string to the stdout
 * @str: Stiring to be printed
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
	return (write(1, str, _strlen(str)));
}

/**
 * print_char - Prints a single character to stdout
 * @ch: The character to print
 *
 * Return: On success 1, on error -1.
 */
int print_char(char ch)
{
	return (write(1, &ch, 1));
}
