#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
* _printf - Printing the  function
* @format: format.
* Return: chars
*/
int _printf(const char *format, ...)
{
int hello, hi = 0, lindo_chars = 0;
int flags, width, precision, size, buff_ind = 0;
va_list list;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(list, format);
for (hello = 0; format && format[hello] != '\0'; hello++)
{
if (format[hello] != '%')
{
buffer[buff_ind++] = format[hello];
if (buff_ind == BUFF_SIZE)
print_buffer(buffer, &buff_ind);
lindo_chars++;
}
else
{
print_buffer(buffer, &buff_ind);
flags = get_flags(format, &hello);
width = get_width(format, &hello, list);
precision = get_precision(format, &hello, list);
size = get_size(format, &hello);
++hello;
hi = handle_print(format, &hello, list, buffer,
flags, width, precision, size);
if (hi == -1)
return (-1);
lindo_chars += hi;
}
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (lindo_chars);
}

/**
* print_buffer - Printing all the contents of the buffer.
* @buffer: the array chars.
* @buff_ind: an index to add next char.
*/
void print_buffer(char buffer[], int *buff_ind)
{
if (*buff_ind > 0)
write(1, &buffer[0], *buff_ind);
*buff_ind = 0;
}
