#include "main.h"

/**
 * get_flags - will be calculating active flags
 * @i: will be taking a parameter.
 * @format: the formatted string in which to print the arguments
 * Return: will be flags
 */
int get_flags(const char *format, int *i)
{
int j, lindo;
int flags = 0;
const char NO[] = {'-', '+', '0', '#', ' ', '\0'};
const int YES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (lindo = *i + 1; format[lindo] != '\0'; lindo++)
{
for (hitty = 0; NO[hitty] != '\0'; hitty++)
if (format[lindo] == NO[hitty])
{
flags |= YES[hitty];
break;
}
if (NO[hitty] == 0)
break;
}
*i = lindo - 1;
return (flags);
}
