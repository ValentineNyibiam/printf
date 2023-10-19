#include "main.h"

/**
 * format_handler - Handles format specifiers
 * @fchar: Character that determines the how to handle the variable argument
 * @vargs: The variable argument to format and print
 *
 * Return: The number of characters printed to stdout
 */
int format_handler(va_list vargs, char fchar)
{
	if (fchar == 's')
	{
		char *strings = va_arg(vargs, char *);

		if (strings == NULL)
			return (print_string("(null)"));
		return (print_string(strings));
	}
	else if (fchar == 'c')
		return (print_char(va_arg(vargs, int)));
	else if (fchar == '%')
		return (print_char('%'));
	else if (fchar == 'd' || fchar == 'i')
		return (print_num(va_arg(vargs, int)));
	else if (fchar == 'b')
		return (print_binary(va_arg(vargs, unsigned int)));
	else if (fchar == 'o')
		return (print_octal(va_arg(vargs, unsigned int)));
	else if (fchar == 'u')
		return (print_ui(va_arg(vargs, unsigned int)));
	else if (fchar == 'x')
		return (print_hex(va_arg(vargs, unsigned int)));
	else if (fchar == 'X')
		return (print_Hex(va_arg(vargs, unsigned int)));

	return (print_char('%') + print_char(fchar));
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
	if (!str)
		str = "(nil)";

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

/**
 * print_num - Prints a number to the stdout
 * @num: The number to be printed to the stdout
 *
 * Return: Number of characters of the printed number
 */
int print_num(int num)
{
	/* Initialize and assign variables */
	int num_digit, num_renew, num_div = 1, num_out = 0, ncount = 0;

	/* Check if num is positive or negative */
	if (num < 0)
	{
		ncount++;
		print_char('-');
		num_digit = -num;
	}
	else
		num_digit = num;
	num_renew = num_digit;

	/* Check for the number of digits */
	while (num_digit > 9)
	{
		num_div *= 10;
		num_digit /= 10;
	}

	/* Print the integer to the stdout */
	while (num_div >= 1)
	{
		num_out = (num_renew / num_div) % 10;
		print_char(num_out + 48);
		num_div /= 10;
		ncount++;
	}

	return (ncount);
}
