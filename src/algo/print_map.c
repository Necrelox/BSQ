/*
** EPITECH PROJECT, 2020
** print_map
** File description:
** print the map
*/

#include "bsq.h"

void print_map(unsigned char **restrict map, long x_max )
{
    for (register int i = 0; map[i] != NULL; i++)
        PRINT(map, i, x_max);
}