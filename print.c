#include "print.h"
#include <unistd.h>

void print_base(long n, int base)
{
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= base)
        print_base(n / base, base);
    write(1, &"0123456789ABCDEF"[n % base], 1);
}

void print_double(double n)
{
    int d = (int)n;
    print_base(d, 10);
    write(1, ".", 1);
    n -= d;
    for (int i = 0; i < 6; i++) {
        n *= 10;
        d = (int)n;
        print_base(d, 10);
        n -= d;
    }
}

void print_float(float n)
{
    int d = (int)n;
    print_base(d, 10);
    write(1, ".", 1);
    n -= d;
    for (int i = 0; i < 6; i++) {
        n *= 10;
        d = (int)n;
        print_base(d, 10);
        n -= d;
    }
}

void print_str(const char *s)
{
    int size = 0;
    while (s[size])
        size++;
    write(1, s, size);
}

int print_impl(size_t n, const var_t var[])
{
    for (size_t i = 0; i < n; i++) {
        switch (var[i].type) {
            case 'd':   print_base(var[i].data.d, 10); break;
            case 'f':   print_double(var[i].data.f); break;
            case 'F':   print_float(var[i].data.F); break;
            case 's':   print_str(var[i].data.s); break;
            case 'c':   write(1, &var[i].data.c, 1); break;
            case '#':
                write(1, "[UNDEFINED]", 11);
        }
    }
    return 0;
}
