/*
** EPITECH PROJECT, 2020
** get_and_verif
** File description:
** verif and open file
*/

#include "bsq.h"

int get_and_verif_(char *restrict path, bsq_s *restrict bsq)
{
    struct stat info;

    if (stat(path, &info) == -1)
        return FILE_NOT_EXIST;
    if (S_ISDIR(info.st_mode) == 1)
        return IS_DIRECTORY;
    if (info.st_size == 0)
        return FILE_EMPTY;
    bsq->fd = open(path, O_RDONLY & O_ASYNC);
    if (bsq->fd < 0)
        return ERROR_OPEN;
    bsq->buff = malloc(sizeof(char) * (info.st_size + 1));
    if (!bsq->buff)
        return ERROR_MEM;
    if ((read(bsq->fd, bsq->buff, info.st_size)) == -1)
        return ERROR_READ;
    bsq->buff[info.st_size] = '\0';
    if (close(bsq->fd) < 0)
        return ERROR_CLOSE;
    return 0;
}