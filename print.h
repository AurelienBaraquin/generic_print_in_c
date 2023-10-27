#ifndef PRINT_H_
    #define PRINT_H_

    #include <sys/types.h>

    #define CHOOSE __builtin_choose_expr
    #define IFTYPE(X, T) __builtin_types_compatible_p(typeof(X), T)

    #define VAR(X)                                          \
        CHOOSE(IFTYPE(X, int),          make_var_d,         \
        CHOOSE(IFTYPE(X, const char[]), make_var_s,         \
        CHOOSE(IFTYPE(X, char *),       make_var_s,         \
        CHOOSE(IFTYPE(X, const char *), make_var_s,         \
        CHOOSE(IFTYPE(X, char),         make_var_c,         \
        CHOOSE(IFTYPE(X, double),       make_var_f,         \
        CHOOSE(IFTYPE(X, float),        make_var_F,         \
                                        make_var_0)))))))(X)

    #define PRINT0() print_impl(0, NULL)
    #define PRINT1(_1) print_impl(1, (var_t[]) \
    {VAR(_1)})
    #define PRINT2(_1, _2) print_impl(2, (var_t[]) \
    {VAR(_1), VAR(_2)})
    #define PRINT3(_1, _2, _3) print_impl(3, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3)})
    #define PRINT4(_1, _2, _3, _4) print_impl(4, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3), VAR(_4)})
    #define PRINT5(_1, _2, _3, _4, _5) print_impl(5, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3), VAR(_4), VAR(_5)})
    #define PRINT6(_1, _2, _3, _4, _5, _6) print_impl(6, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3), VAR(_4), VAR(_5), VAR(_6)})
    #define PRINT7(_1, _2, _3, _4, _5, _6, _7) print_impl(7, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3), VAR(_4), VAR(_5), VAR(_6), VAR(_7)})
    #define PRINT8(_1, _2, _3, _4, _5, _6, _7, _8) print_impl(8, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3), VAR(_4), VAR(_5), VAR(_6), VAR(_7), VAR(_8)})
    #define PRINT9(_1, _2, _3, _4, _5, _6, _7, _8, _9) print_impl(9, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3), VAR(_4), VAR(_5), \
    VAR(_6), VAR(_7), VAR(_8), VAR(_9)})
    #define PRINT10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10) \
    print_impl(10, (var_t[]) \
    {VAR(_1), VAR(_2), VAR(_3), VAR(_4), VAR(_5), VAR(_6), \
    VAR(_7), VAR(_8), VAR(_9), VAR(_10)})

    #define SELECT_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N

    #define print(...) SELECT_N(__VA_ARGS__, PRINT10, PRINT9, PRINT8, \
        PRINT7, PRINT6, PRINT5, PRINT4, PRINT3, PRINT2, PRINT1)(__VA_ARGS__)


    typedef struct var_t var_t;

    struct var_t {
        int type;
        union {
            int d;
            double f;
            float F;
            char *s;
            const char c;
        } data;
    };

    var_t make_var_d(int X);
    var_t make_var_s(const char *X);
    var_t make_var_f(double X);
    var_t make_var_c(char X);
    var_t make_var_F(float X);
    var_t make_var_0(void);

    int print_impl(size_t n, const var_t var[]);

    #define FOR_EACH(x) for (int x##_ = 0; x[x##_]; x##_++)

#endif /* !PRINT_H_ */