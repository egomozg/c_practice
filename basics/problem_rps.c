//
//
// тесты проходит, но программа как по мне шляпа.
// после гугления понял что возможно нужно искать другие подходы
// с функцией эйлера
//
//
#include <stdio.h>
#include <assert.h>

int pow_mod(int n, int p, int m)
{
    int mult = n;
    int prod = 1;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            prod = (prod * mult) % m;
        }
        mult = (mult * mult) % m;

        p /= 2;
    }

    return prod;
}

unsigned spow_mod(unsigned n, unsigned k, unsigned m) {
    unsigned mult = n;

    while (k > 1) {
        mult = pow_mod(n, mult, m);
        k--;
    }

    return mult;

}

int main()
{
    unsigned a = 0, b = 0, m = 0;
    int res = scanf("%u%u%u", &a, &b, &m);
    assert(res == 3);
    printf("%d", spow_mod(a, b, m));
    return 0;
}
