#include "main.h"

/**
 * get_flags - will be calculating an active flags
 * @i: takesthe parameter.
 * @format: Formatted string in which to print the arguments
 * Return: the flags:
 */
int get_flags(const char *format, int *i)
{
int j, lindo;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
for (lindo = *i + 1; format[lindo] != '\0'; lindo++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
if (format[lindo] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}
if (FLAGS_CH[j] == 0)
break;
}
*i = lindo - 1;
return (flags);
}
