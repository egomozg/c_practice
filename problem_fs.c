#include <stdio.h>
#include <assert.h>

#define ARR_SIZE 32

// factorial system
void print_fs_converted(unsigned n) {
    int container[ARR_SIZE] = {0};
    int factorial_base = 2;
    int i = 0;
    while (n > 0) {
        container[i] = n % factorial_base;
        n /= factorial_base++;
        i++;
    }

    for (int k = 0; k < i / 2; k++) {
        int temp = container[k];
        container[k] = container[i - k - 1];
        container[i - k - 1] = temp;
    }

    for (int k = 0; k < i; k++) {
        printf("%d.", container[k]);
    }

}

int main() {
    int n = 0;
    int res = 0;
    res = scanf("%d", &n);
    assert(res == 1);
    print_fs_converted(n);

    return 0;
}
