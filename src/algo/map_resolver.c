/*
** EPITECH PROJECT, 2020
** map_resolver
** File description:
** resolv map
*/

#include "bsq.h"

unsigned char **draw_square(unsigned char **restrict map, int value_max, int *restrict y, int *restrict x)
{
    int pos = *x;

    for (register int k = value_max - 48; k > 0 && map[*y]; *y += 1, k--) {
        map[*y][pos] = 'x';
        for (;*x < pos; *x += 1)
            map[*y][*x] = TRANSFORM_MAP(map[*y][*x]);
        map[*y][*x] = '\n';
        for (register int i = value_max-48; i > 0 && map[*y][*x]; i--, *x += 1)
            map[*y][*x] = 'x';
        for (;*x > pos && map[*y][*x]; *x += 1)
            map[*y][*x] = TRANSFORM_MAP(map[*y][*x]);
        map[*y][*x] = '\n';
        *x = 0;
    }
    return map;
}

unsigned char **set_map(unsigned char **restrict map, int value_max)
{
    int y = 0, x = 0;

    for (;map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0' && map[y][x] != value_max; x++)
            map[y][x] = TRANSFORM_MAP(map[y][x]);
        if (map[y][x] == value_max)
            break;
        map[y][x] = '\n';
    }
    map = draw_square(map, value_max, &y, &x);
    for (;map[y] != NULL; y++) {
        for (x = 0; map[y][x] != '\0'; x++)
            map[y][x] = TRANSFORM_MAP(map[y][x]);
        map[y][x] = '\n';
    }
    return map;
}

int compare_side(int y, int x, unsigned char **restrict map)
{
    int a = map[y][x+1] - 48, b = map[y+1][x] - 48, c = map[y+1][x+1] - 48;
    int value = COMPARE(value, a, b, c);

    return value;
}

void resolver(bsq_s *restrict bsq)
{
    bsq->value_max = '1';
    for (register int y = bsq->y_max - 2; y >= 0; y--) {
        for (register int x = bsq->x_max - 2; x >= 0; x--) {
            if (bsq->map[y][x] != '0')
                bsq->map[y][x] = compare_side(y, x, bsq->map) + 48;
            bsq->value_max = bsq->value_max <= bsq->map[y][x] ?
                bsq->map[y][x] :bsq->value_max;
        }
    }
    bsq->map = set_map(bsq->map, bsq->value_max);
}