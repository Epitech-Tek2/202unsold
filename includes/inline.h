/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-202unsold-clement.muth [WSL: Ubuntu]
** File description:
** inline
*/

#pragma once

#include "unsold.h"

extern calc_t *calc;

static __always_inline void init_calc()
{
    calc->result_x = malloc(sizeof(map_t) * 51);
    calc->result_y = malloc(sizeof(map_t) * 51);
    calc->z = malloc(sizeof(map_t) * 101);
    calc->result_x[10].value = calc->result_y[10].value = 0;
    calc->result_x[20].value = calc->result_y[20].value = 0;
    calc->result_x[30].value = calc->result_y[30].value = 0;
    calc->result_x[40].value = calc->result_y[40].value = 0;
    calc->result_x[50].value = calc->result_y[50].value = 0;
    calc->z[20].value = 0;
    calc->z[30].value = 0;
    calc->z[40].value = 0;
    calc->z[50].value = 0;
    calc->z[60].value = 0;
    calc->z[70].value = 0;
    calc->z[80].value = 0;
    calc->z[90].value = 0;
    calc->z[100].value = 0;
}

static void (my_free)(int _count, void *_ptr, ...)
{
    va_list list_ptr;

    free(_ptr);
    for (va_start(list_ptr, _ptr); _count > 0; --_count)
        free(va_arg(list_ptr, void *));
    va_end(list_ptr);
}
