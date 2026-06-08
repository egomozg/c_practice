//
// my first-thought solution, before golfing.
//
#include <stdio.h>

void position_of_high_and_low_bits(unsigned n) {
    if (n == 0) { printf("NO\n"); return; }

    int high = 31;
    while (((n >> high) & 1) == 0) {
        high -= 1;
    }

    int low = 0;
    while (((n >> low) & 1) == 0) {
        low += 1;
    }

    printf("%d %d\n", high, low);

}

int main(void) {
    unsigned input = 0;
    scanf("%d", &input);
    position_of_high_and_low_bits(input);
    return 0;
}
