/*
** EPITECH PROJECT, 2020
** init_map
** File description:
** initialize map
*/

#include "bsq.h"

char *decal_second_line(char *restrict str)
{
    for (;*str != '\n'; str++);
    return &*str;
}

void error_free_map(unsigned char **restrict map, int i)
{
    i += 1;
    for (register int j = 0; i > 0; j++, i--)
        free (map[j]);
    free(map);
}

int init_map(bsq_s *restrict bsq)
{
    register int i = 0; // registre cpu 

/* point */
    if (my_getnbr(bsq->buff, &bsq->y_max) < 0) return NOT_NUMBER_FIRST_LINE;
    if (!(bsq->map = malloc(sizeof(char *) * (bsq->y_max+1)))) return ERROR_MEM;
    bsq->buff = decal_second_line(bsq->buff);
    bsq->x_max = my_strlen(++bsq->buff, '\n');
    for (register int j = 0; i < bsq->y_max; i++) {
        bsq->map[i] = malloc(sizeof(char) * (bsq->x_max + 1));
        for (j = 0; *bsq->buff != '\n' && *bsq->buff; bsq->buff++, j++) {
            bsq->map[i][j] = *bsq->buff == '.' ? '1' : '0';
            if ((*bsq->buff != '.' && *bsq->buff != 'o') && (*bsq->buff != '\n'
                && *bsq->buff != '\0')) { error_free_map(bsq->map, i);
                return ERROR_MAP; } }
        bsq->map[i][j] = '\0';
        *bsq->buff == '\n' ? bsq->buff++ :0;
        if (*bsq->buff == '\0' && i+1 < bsq->y_max) {
            error_free_map(bsq->map, i);
            return ERROR_MAP; }
    }
    bsq->map[i] = NULL;
    return 0;
}