#include "print.h"

var_t make_var_d(int X)
{
    var_t v = {'d', {.d = X}};
    return v;
}

var_t make_var_s(const char *X)
{
    var_t v = {'s', {.s = X}};
    return v;
}

var_t make_var_f(double X)
{
    var_t v = {'f', {.f = X}};
    return v;
}

var_t make_var_c(char X)
{
    var_t v = {'c', {.c = X}};
    return v;
}

var_t make_var_F(float X)
{
    var_t v = {'F', {.F = X}};
    return v;
}

var_t make_var_0(void)
{
    var_t v = {'#', {.d = 0}};
    return v;
}
