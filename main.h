#ifndef MAIN_H
#define MAIN_H

/* Standard header files */
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

/* Protoypes */
int _printf(const char *format, ...);
int print_char(char ch);
int format_handler(va_list vargs, char fchar);
int print_string(char *str);
int print_num(int num);
int print_binary(unsigned int num);
int print_ui(unsigned int num);
int print_octal(unsigned int num);
int _strlen(char *str);
int print_Hex(unsigned int num);
int print_hex(unsigned int num);

#endif /* MAIN_H */
