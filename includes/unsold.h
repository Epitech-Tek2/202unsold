/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-202unsold-clement.muth [WSL: Ubuntu]
** File description:
** unsold
*/

#pragma once

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdnoreturn.h>
#include "../library/includes/assert.h"


typedef struct calc_s calc_t;
typedef struct map_s map_t;
typedef struct minint_s minint_t;
typedef struct mminint_s mminint_t;

#define generate_table(init, to, inc, c) ({ \
    for (minint_t i = {init}; i.i < to; i.i += inc) printf(c); \
    printf("\n"); \
})

#define my_free(ptr, ...) my_free(_N__ARG(__VA_ARGS__), ptr, __VA_ARGS__)

#define RAW "\tX=10\tX=20\tX=30\tX=40\tX=50\tY law\n"

struct calc_s
{
    vect3f expect;
    vect3f variance;
    vect2i params;
    map_t *result_x;
    map_t *result_y;
    map_t *z;
};

struct minint_s
{
    unsigned int i : 6;
};

struct mminint_s
{
    unsigned int i : 7;
};

struct map_s
{
    float value;
};

#include "inline.h"
