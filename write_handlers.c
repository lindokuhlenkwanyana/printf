#include "main.h"

/**
 * handle_write_char - will be printingthe string
 * @c: the char types.
 * @buffer: the buffer array to handle print
 * @flags: will be calculating the active flags.
 * @width: the get width.
 * @precision: the precision specifier
 * @size: the size specifier
 * Return: Number of chars to be printed.
 */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{
int mlindos = 0;
char padd = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
padd = '0';
buffer[mlindos++] = c;
buffer[mlindos] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (mlindos = 0; mlindos < width - 1; mlindos++)
buffer[BUFF_SIZE - mlindos - 2] = padd;
if (flags & F_MINUS)
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - mlindos - 1], width - 1));
else
return (write(1, &buffer[BUFF_SIZE - mlindos - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}

/**
 * write_number - will be printing a string
 * @ind: the char types.
 * @buffer: the buffer array to handle print
 * @flags:  will be calculating active flags
 * @width: the get width.
 * @is_negative: the lista of arguments
 * @precision: the precision specifier
 * @size: the size specifier
 * Return: Number chars that will be printed.
 */

int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1;
char padd = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (is_negative)
extra_ch = '-';
else if (flags & F_PLUS)
extra_ch = '+';
else if (flags & F_SPACE)
extra_ch = ' ';
return (write_num(ind, buffer, flags, width, precision,
length, padd, extra_ch));
}

/**
 * write_num - Writing the number using a bufffer
 * @width: the width
 * @buffer: the buffer
 * @flags: the flags
 * @prec: Precision specifier
 * @length: the number length
 * @padd: the pading char
 * @extra_c: the extra char
 * @ind: Index at which the number starts on the buffer
 * Return: Number of the chars to be printed
 */

int write_num(int ind, char buffer[],
int flags, int width, int prec,
int length, char padd, char extra_c)
{
int helloz, padd_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd = ' '; 
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
buffer[--ind] = '0', length++;
if (extra_c != 0)
length++;
if (width > length)
{
for (helloz = 1; helloz < width - length + 1; helloz++)
buffer[helloz] = padd;
buffer[helloz] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[1], helloz - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], helloz - 1) + write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
return (write(1, &buffer[padd_start], helloz - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writing the unsigned number
 * @size: the size specifier
 * @is_negative: the number that's indicates if the num is negative
 * @buffer: the array of chars
 * @flags: the flags specifier
 * @ind: the index at which the number starts in the buffer
 * @width: the width specifier
 * @precision: the precision specifier
 * Return: the number of written chars.
 */

int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size)
{
int length = BUFF_SIZE - ind - 1, hello = 0;
char hitty = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
return (0);  
if (precision > 0 && precision < length)
hitty = ' ';
while (precision > length)
{
buffer[--ind] = '0';
length++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
hitty = '0';
if (width > length)
{
for (hello = 0; hello < width - length; hello++)
buffer[hello] = hitty;
buffer[hello] = '\0';
if (flags & F_MINUS)
{
return (write(1, &buffer[ind], length) + write(1, &buffer[0], hello));
}
else 
{
return (write(1, &buffer[0], hitty) + write(1, &buffer[ind], length));
}
}
return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - will be Writing a memory address
 * @buffer: the arrays of chars
 * @padd_start: the index at which padding should start
 * @ind: the index at which the number starts in the buffer
 * @flags: the flags specifier
 * @width: the width specifier
 * @padd: the char representing the padding
 * @extra_c: the char representing extra char
 * @length: the length of number
 * Return: the number of chars.
 */

int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int lindo;
if (width > length)
{
for (lindo = 3; lindo < width - length + 3; lindo++)
buffer[lindo] = padd;
buffer[lindo] = '\0';
if (flags & F_MINUS && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) + write(1, &buffer[3], lindo - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], lindo - 3) + write(1, &buffer[ind], length));}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], lindo - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
