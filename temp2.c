#include <stdio.h>

int main(void) {
    unsigned a = 0b10000000;
    unsigned res = 0;
    scanf("%u", &res);
    printf("(a >> res) & 1: %u\n", (a >> res) & 1);
    printf("%x", (1u << res));

    return 0;
}
