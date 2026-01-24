#include <assert.h>
#include <stdio.h>

typedef long long ll;

ll iabs(ll x) {return (x < 0) ? -x : x;}

ll eu_mod(ll x, ll y) {
    assert (y != 0);
    return iabs(x % y);
}

void gcde(ll x, ll y) {
    ll r = 1;
    ll q;
    ll s_0 = 1;
    ll s_1 = 0;
    ll s;
    ll t_0 = 0;
    ll t_1 = 1;
    ll t;

    while (r != 0) {
        r = x % y;
        q = x / y;
        x = y;
        y = r;

        s = s_0 - q * s_1;
        s_0 = s_1;
        s_1 = s;

        t = t_0 - q * t_1;
        t_0 = t_1;
        t_1 = t;
    }

    if (x < 0)
        printf("%lld %lld %lld", -s_0, -t_0, -x);
    else
        printf("%lld %lld %lld", s_0, t_0, x);

}

int main() {
  ll x = 0, y = 0;
  int res;

  res = scanf("%lld %lld", &x, &y);
  assert(res == 2);
  gcde(x, y);
  return 0;
}
