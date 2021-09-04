/*
** EPITECH PROJECT, 2020
** main
** File description:
** entry point
*/

#include "bsq.h"

void free_bsq(bsq_s *restrict bsq)
{
    for (register int i = 0; bsq->map[i] != NULL; i++)
        free (bsq->map[i]);
    free (bsq->map);
    free (bsq);
}

int parse_bsq(char *path)
{
    char *restrict tmp;
    bsq_s *restrict bsq = malloc(sizeof(*bsq));
    if (!bsq)
        return ERROR;
    if (get_and_verif_(path, bsq) < 0) {
        free (bsq);
        return ERROR;
    }
    tmp = bsq->buff;
    if (init_map(bsq) < 0) {
        free (tmp);
        free (bsq);
        return ERROR;
    }
    free (tmp);
    resolver(bsq);
    print_map(bsq->map, bsq->x_max);
    free_bsq(bsq);
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        if (parse_bsq(av[1]) == 84)
            return ERROR;
        return 0;
    }
    return ERROR;
}