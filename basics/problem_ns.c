#include <stdio.h>
#include <assert.h>

#define ARR_SIZE 32

void print_converted(unsigned n, unsigned base) {
    assert(base <= 10);
    int container[ARR_SIZE] = {0};
    int i = 0;
    while (n > 0) {
        container[i] = n % base;
        n /= base;
        i++;
    }

    for (int k = 0; k < i / 2; k++) {
        int temp = container[k];
        container[k] = container[i - k - 1];
        container[i - k - 1] = temp;
    }

    for (int k = 0; k < i; k++) {
        printf("%d", container[k]);
    }

}

int main() {
    int n = 0;
    int base = 0;
    int res = 0;
    res = scanf("%d%d", &n, &base);
    assert(res == 2);
    print_converted(n, base);

    return 0;
}
