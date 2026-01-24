#include <assert.h>
#include <stdio.h>

long long iabs(long long x) {return (x < 0) ? -x : x;}

long long eu_mod(long long x, long long y) {
    assert (y != 0);
    return iabs(x % y);
}

long long gcd(long long x, long long y) {
    long long q;
    if (y > x) {
        q = x; x = y; y = q;
        do {
            q = eu_mod(x, y);
            x = y;
            y = q;
        } while (q != 0);
    } else {
        do {
            q = eu_mod(x, y);
            x = y;
            y = q;
        } while (q != 0);
    }

    return x;
}

int main() {
  long long x = 0, y = 0, g;
  int res;

  res = scanf_s("%lld %lld", &x, &y);
  assert(res == 2);
  g = gcd(x, y);
  printf("%lld\n", g);
  return 0;
}
