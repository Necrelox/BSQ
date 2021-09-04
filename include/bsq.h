/*
** EPITECH PROJECT, 2020
** bsq
** File description:
** bsq header
*/

#ifndef BSQ_H_
#define BSQ_H_

#define FILE_NOT_EXIST -1
#define IS_DIRECTORY -2
#define FILE_EMPTY -3
#define ERROR_OPEN -4
#define ERROR_CLOSE -5
#define ERROR_READ -6
#define NOT_NUMBER_FIRST_LINE -7
#define ERROR_MAP -8
#define ERROR_MEM -10

#define ERROR 84

#include "my.h"
#include <time.h>

    
typedef struct bsq_t
{
    long y_max, x_max;
    int fd;
    int value_max;
    char *restrict buff;
    unsigned char **restrict map;
}bsq_s;

#define PRINT(map, i, x_max) (write ((1), (map[(i)]), (x_max) + (1)))

#define TRANSFORM_MAP(c) ((c) != ('0') ? ('.') : ('o'))

#define COMPARE(value, a, b, c)                                              \
    ((a) == (b) && (b) == (c) ? (value = (a + 1)) : (0));                    \
    ((a) == (0) || (b) == (0) || (c) == (0) ? (value = 1) : (0));            \
    ((a) <= (b) && (a) <= (c) && (value) == (0) ? (value = a + 1) : (0));    \
    ((b) <= (a) && (b) <= (c) && (value) == (0) ? (value = b + 1) : (0));    \
    ((c) <= (a) && (c) <= (b) && (value) == (0) ? (value = c + 1) : (0))

/*  SRC/INPUT_FILE/open_and_verif.c */
int get_and_verif_(char *path, bsq_s *bsq);

/*  SRC/ALGO/map.c */
int init_map(bsq_s *bsq);

/*  SRC/ALGO/print_map.c */
void print_map(unsigned char **map, long x_max );

/*  SRC/ALGO/map_resolver.c */
void resolver(bsq_s *bsq);

#endif /* !BSQ_H_ */