#include "main.h"

/**
 * get_width - will be Calculating the width for printing
 * @list: the arguments list
 * @format: the formatted string in which to print the arguments.
 * @i: the list of arguments that will be printed.
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
int lindo;
int hitty = 0;
for (lindo = *i + 1; format[lindo] != '\0'; lindo++)
{
if (is_digit(format[lindo]))
{
hitty *= 10;
hitty += format[lindo] - '0';
}
else if (format[lindo] == '*')
{
lindo++;
hitty = va_arg(list, int);
break;
}
else
break;
}
*i = lindo - 1;
return (hitty);
}
