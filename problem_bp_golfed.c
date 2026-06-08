//
// My initial thought was to separately walk from left
// and right to find highest and lowest bits respectively.
// But then I realized it's stupid on constant 32/64 bit word,
// so I shrinked it into one loop.
//
// But maybe it was not that stupid, cuz my first thought was
// more readable IMO and compiler produced much smaller code for it.
//
// https://godbolt.org/z/advvbPv1Y
//
// Yep, I think two loops were objectively better.
//
#include <stdio.h>

void position_of_high_and_low_bits(unsigned n) {
    if (n == 0) { printf("NO\n"); return; }

    int low_bit = -1;
    int high_bit = -1;

    for (int i = 0; i < 32; i++) {
        if (((n >> i) & 1) == 1) {
            if (low_bit == -1)
                low_bit = i;
            high_bit = i;
        }
    }
    printf("%d %d\n", high_bit, low_bit);

}

int main(void) {
    unsigned input = 0;
    scanf("%d", &input);
    position_of_high_and_low_bits(input);
    return 0;
}
