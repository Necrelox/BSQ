/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** get nbr in a string
*/

#include "my.h"

int verif_number(char *str)
{
    register int i = 0;
    for (; str[i] >= '0' && str[i] <= '9' && str[i] != '\n' && str[i]; i++);
    if (str[i] == '\0' || str[i] == '\n')
        return 1;
    return 0;
}

int my_getnbr(char *str, long *y_max)
{
    long result = 0;
    int get = 0, sign = 0;

    if (verif_number(str) == 0)
        return -7;
    for (;(*str < 48 || *str > 57) && *str != '\0'; str++) {
        *str == '+' ? sign = 0, str++ :0;
        *str == '-' ? sign = 1, str++ :0;
    }
    for ( ; *str != '\n' && *str != '\0'; str++) {
        get = *str;
        if (get < 48 || get > 57)
            break;
        get -= '0';
        result = get + (10 * result);
    }
    *y_max = sign != 0 ? - result : result;
    return 0;
}