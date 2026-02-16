#include <stdio.h>
#include <assert.h>

int get_pisano_period(unsigned m) {
    int counter = 0;

    assert(m != 0);
    unsigned long long f1 = 0ull;
    unsigned long long f2 = 1ull;
    unsigned long long temp = 0ull;

    do {
       counter++;
       temp = f2 % m;
       f2 = (f2 + f1) % m;
       f1 = temp;
    } while (!(f1 == 0 && f2 == 1));

    return counter;
}

unsigned long long fib_mod(unsigned long long n, unsigned m) {
    assert(m != 0);
    unsigned long long f1 = 0ull;
    unsigned long long f2 = 1ull;
    unsigned long long temp = 0ull;
    int i = 0;
    if (n == 0) return f1;
    if (n == 1) return f2;
    n = n % get_pisano_period(m);
    for (i = 2; i <= n; ++i) {
        temp = f2 % m;
        f2 = (f2 + f1) % m;
        f1 = temp;
    }

    return f2;
}

int main() {
    int x = 0ull;
    int m = 0u;
    int i = 0;
    int res = 0;
    res = scanf("%u%u", &x, &m);
    if (res != 2) { printf("Wrong input\n"); return -1; }
    printf("%llu", fib_mod(x, m));
    return 0;
}
