#include <stdio.h>
#include <assert.h>

void cf(int x, int y) {
    assert(y != 0);
    int q;

    printf("%d ", x / y);
    q = x % y;

    while (q != 0) {
        printf("%d ", y / q);
        x = y;
        y = q;
        q = x % y;
    }
}

int main() {
    int x, y;
    int res;

    res = scanf("%d%d", &x, &y);
    assert(res == 2);
    cf(x, y);
    return 0;
}
