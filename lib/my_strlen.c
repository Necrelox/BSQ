/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

long my_strlen(char *str, char sep)
{
    long i = 0;
    for (;str[i] != '\0' && str[i] != sep; i++);
    return i;
}