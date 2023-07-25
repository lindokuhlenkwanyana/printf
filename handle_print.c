#include "main.h"
/**
 * handle_print - will be printing an argument based on its type
 * @list: the List of argumentthat will be printed.
 * @fmt: will be formatted string in which to print the arguments.
 * @ind: the ind.
 * @precision: the precision specification
 * @buffer: the buffer array to handle print.
 * @flags: will calculate the  active flags
 * @width: the get width.
 * @size: the size specifier
 * Return: between 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
int lindo, hello = 0, hi = -1;
fmt_t fmt_types[] = {
{'c', print_char}, {'s', print_string}, {'%', print_percent},
{'i', print_int}, {'d', print_int}, {'b', print_binary},
{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
};
for (lindo = 0; fmt_types[lindo].fmt != '\0'; lindo++)
if (fmt[*ind] == fmt_types[lindo].fmt)
return (fmt_types[lindo].fn(list, buffer, flags, width, precision, size));
if (fmt_types[lindo].fmt == '\0')
{
if (fmt[*ind] == '\0')
return (-1);
hello += write(1, "%%", 1);
if (fmt[*ind - 1] == ' ')
hello += write(1, " ", 1);
else if (width)
{
--(*ind);
while (fmt[*ind] != ' ' && fmt[*ind] != '%')
--(*ind);
if (fmt[*ind] == ' ')
--(*ind);
return (1);
}
hello += write(1, &fmt[*ind], 1);
return (hello);
}
return (hi);
}
