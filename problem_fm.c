#include <stdio.h>
#include <assert.h>

unsigned long long fib_mod(unsigned n, unsigned m) {
    assert(m != 0);
    unsigned long long f1 = 0ull;
    unsigned long long f2 = 1ull;
    unsigned long long temp = 0ull;
    int i = 0;
    if (n == 0) return f1;
    if (n == 1) return f2;
    for (i = 2; i <= n; ++i) {
        temp = f2 % m;
        f2 = (f2 + f1) % m;
        f1 = temp;
    }

    return f2;
}

int main() {
    unsigned x = 0;
    unsigned m = 0;
    int i = 0;
    int res = 0;
    res = scanf("%u%u", &x, &m);
    if (res != 2) { printf("Wrong input\n"); return -1; }
    printf("%llu", fib_mod(x, m));
    #if 0
    for (i = 0; i <= 30; ++i) {
        printf("%llu", fib_mod(i, m));
    }
    #endif
    return 0;
}
