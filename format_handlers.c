#include "main.h"
#include <stdlib.h>
/**
 * format_handler - Prints to stdout based on the character passed
 * @vargs: The list of variable arguments to print from
 * @fchar: chracter strings
 * Return: The number of characters printed to stdout, success
 * Else -1 for failure
 */
int format_handler(char fchar, va_list vargs)
{
	/*check for fchar and call its func*/
	if (fchar == 'c' || fchar == '%')
		return (print_char(va_arg(vargs, int)));
	else if (fchar == 's')
		return (print_string(va_arg(vargs, char *)));
	else if (fchar == 'i' || fchar == 'd')
		return (print_num(va_arg(vargs, int)));
	else if ((fchar == 'b'))
	{
		unsigned int num;

		num = va_arg(vargs, unsigned int);
		int counter;

		counter = print_bin(num);

		return (counter);
	}
	/* return -1 to indicate unmatching datatype */
	return (-1);
}

/**
 * print_string - Prints a string to the stdout
 * @str: String to be printed
 *
 * Return: the number of characters printed
 */
int print_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		print_char(str[i]);
	}

	return (i);
}

/**
 * print_num - Prints a number to the stdout
 * @num: the integer value to be printed
 *
 * Return: Number of characters printed
 */
int print_num(int num)
{
	/* Initiaze and assign variables */
	int num_digit, num_renew, num_div = 1, num_out = 0, ncount = 0;

	/* Check if num is positive or negative */
	if (num < 0)
	{
		ncount++;
		print_char('-');
		num_digit = -num;
	}
	else
	{
		num_digit = num;
	}
	num_renew = num_digit;

	/* Check for the number of digits */
	while (num_digit > 9)
	{
		num_div *= 10;
		num_digit /= 10;
	}

	/* print the integer to the stdout */
	while (num_div >= 1)
	{
		num_out = (num_renew / num_div) % 10;
		print_char(num_out + 48);
		num_div /= 10;
		ncount++;
	}

	return (ncount);
}


/**
 * print_bin - Print an unsigned number in binary
 * @num: The number to convert
 * Return: The size of the number
 */
int print_bin(unsigned int num)
{
	unsigned int base, num_copy;
	int counter, *result, i;

	base = 2;
	counter = 0;
	num_copy = num;
	result = NULL;

	/* Determine the number of bin digit */
	while (num_copy != 0)
	{
		num_copy /= base;
		counter++;
	}

	/* Allocate Memory for the Result Array */
	result =  malloc(counter * sizeof(int));
	if (result == NULL)
		return (-1);

	/* Reset counter */
	counter = 0;

	/* Calculate binary digits */
	while (num != 0)
	{
		result[counter] = num % base;
		num /= base;
		counter++;
	}
	i = 0;

	for (i = counter - 1; i >= 0; i--)
		print_char(result[i] + '0');

	free(result);

	return (counter);
}
