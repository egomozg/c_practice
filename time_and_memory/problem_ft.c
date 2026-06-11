#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned long long ull;

ull pow_mod(ull n, ull p, ull m);
char fermat_test(ull p);

int main(void) {
  ull p;
  srand(time(NULL));
  if (scanf("%llu", &p) == 1) {
    printf("%d\n", fermat_test(p));
  }

  return 0;
}

char fermat_test(ull p) {
  int i;
  ull a;
  for (i = 0; i < 100; ++i) {
    a = (rand() % (p - 2)) + 2;
    ull res = pow_mod(a, p - 1, p);
    if (res != 1)
      return 0;
  }

  return 1;
}

ull pow_mod(ull n, ull p, ull m) {
  assert(m > 1);
  if (p == 0)
    return 1;
  ull mult = n % m;
  ull prod = 1;
  while (p > 0) {
    if ((p % 2) == 1)
      prod = (prod * mult) % m;
    mult = (mult * mult) % m;
    p /= 2;
  }

  return prod;
}
