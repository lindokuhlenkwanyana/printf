#include "main.h"

/**
 * is_printable - will evaluates if a char is printable
 * @c: Char that is  to be evaluated.
 * Return: 1, 0 otherwise
 */
int is_printable(char c)
{
if (c >= 32 && c < 127)
return (1);
return (0);
}

/**
 * append_hexa_code - Added ascci in the hexadecimal code to buffer
 * @buffer: the array of chars.
 * @i: the index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return:  3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
char map_to[] = "0123456789ABCDEF";

if (ascii_code < 0)
ascii_code *= -1;
buffer[i++] = '\\';
buffer[i++] = 'x';
buffer[i++] = map_to[ascii_code / 16];
buffer[i] = map_to[ascii_code % 16];
return (3);
}

/**
 * is_digit - it will verify if a char is a digit
 * @c: Char that is to be evaluated
 * Return: 1, 0 otherwise
 */
int is_digit(char c)
{
if (c >= '0' && c <= '9')
return (1);
return (0);
}

/**
 * convert_size_number - will be casting the number to the specified size
 * @size: Number indicating the type to be casted.
 * @num: the number that is to be casted.
 * Return: Casted value
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((short)num);
return ((int)num);
}

/**
 * convert_size_unsgnd - will be Casting the number to the specified size
 * @size: Number indicating the type to be casted
 * @num: the number that is to be casted
 * Return: Casted value
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
return (num);
else if (size == S_SHORT)
return ((unsigned short)num);
return ((unsigned int)num);
}
