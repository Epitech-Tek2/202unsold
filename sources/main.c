/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-202unsold-clement.muth [WSL: Ubuntu]
** File description:
** main
*/

#include "unsold.h"

calc_t *calc = NULL;

noreturn bool help(char const *restrict _filepath)
{
    char *lineptr = NULL;
    size_t i = 500;
    FILE *stream = GET(FILE *, {
        my_assert(_filepath, PROTO_DATA, ASSERT_INFO("Cannot read property '_filepath' of undefined", ERR_TYPE, FAIL_EXEC), NULL);
        return (fopen(_filepath, "r"));
    });

    while (-1 != getline(&lineptr, &i, stream) && (printf("%s", lineptr)));
    free(lineptr);
    fclose(stream);
    exit(0);
}

void display_xy()
{
    float result, sum = 0.0;

    generate_table(0, 60, 1, "-");
    printf(RAW);
    for (minint_t i = {10}; i.i < 60; i.i += 10, sum = 0) {
        printf("Y=%d\t", i.i);
        for (minint_t y = {10}; y.i < 60; y.i += 10) {
            result = (calc->params.x - y.i) * (calc->params.y - i.i);
            result /= (5 * calc->params.x - 150) * (5 * calc->params.y - 150);
            calc->z[y.i + i.i].value += result;
            calc->result_x[y.i].value += result;
            printf("%.3f\t", result);
            sum += result;
        }
        calc->result_y[i.i].value = sum;
        calc->expect.y += sum * i.i;
        printf("%.3f\n", sum);
    }
    printf("X law\t");
    for (minint_t i = {10}; i.i < 60; i.i += 10) {
        printf("%.3f\t", calc->result_x[i.i].value);
        calc->expect.x += calc->result_x[i.i].value * i.i;
    }
    printf("1.000\n");
    generate_table(0, 60, 1, "-");
}

void display_z()
{
    float sum = 0;

    printf("z\t");
    for (mminint_t i = {20}; i.i <= 100; i.i += 10) printf("%d%s", i.i, (i.i == 100) ? "" : "\t");
    printf("\np(Z=z)\t");
    for (mminint_t i = {20}; i.i <= 100; i.i += 10) {
        calc->expect.z += calc->z[i.i].value * i.i;
        sum += calc->z[i.i].value;
        printf("%.3f%s", calc->z[i.i].value, (i.i == 100) ? "" : "\t");
    }
    printf("\n");
    generate_table(0, 60, 1, "-");
}

void values()
{
    for (minint_t i = {10}; i.i < 60; i.i++)
        calc->variance.x += (calc->result_x[i.i].value * pow(i.i, 2));
    calc->variance.x = calc->variance.x - pow(calc->expect.x, 2);
    for (minint_t i = {10}; i.i < 60; i.i++)
        calc->variance.y += (calc->result_y[i.i].value * pow(i.i, 2));
    calc->variance.y = calc->variance.y - pow(calc->expect.y, 2);
    for (mminint_t i = {20}; i.i <= 100; i.i++)
        calc->variance.z += (calc->z[i.i].value * pow(i.i, 2));
    calc->variance.z = calc->variance.z - pow(calc->expect.z, 2);
    printf("expected value of X:\t%.1f\nvariance of X:\t\t%.1f\nexpected value of Y:\t%.1f\nvariance of Y:\t\t%.1f\nexpected value of Z:\t%.1f\nvariance of Z:\t\t%.1f\n", calc->expect.x, calc->variance.x, calc->expect.y, calc->variance.y, calc->expect.z, calc->variance.z);
    generate_table(0, 60, 1, "-");
}

void unsold(int const a, int const b)
{
    calc = malloc(sizeof(calc_t));
    calc->params = (vect2i){a, b};
    calc->expect = (vect3f){0, 0, 0};
    calc->variance = (vect3f){0, 0, 0};
    /* NOTE - Just for optimizations */
    init_calc();
    display_xy();
    display_z();
    values();
}

int main(int ac, char **av)
{
    if (2 == ac && !strcmp(av[1], "-h")) help("./help.txt");
    my_assert(3 == ac, PROTO_DATA, ASSERT_INFO("Invalid number of arguments", "ParamError", FAIL_EXEC), NULL);
    my_assert((atoi(av[1]) > 50 && atoi(av[2]) > 50), PROTO_DATA, ASSERT_INFO("Invalid number of arguments", "ParamError", FAIL_EXEC), NULL);
    unsold(atoi(av[1]), atoi(av[2]));
    my_free(calc->result_x, calc->result_y, calc->z, calc);
    return (0);
}