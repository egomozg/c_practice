#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct dword_t {
    int num_bytes;
    unsigned char* byte;
} Dword;

Dword init_dword(int num_bytes) {
    Dword dword;
    dword.num_bytes = num_bytes;
    dword.byte = calloc(num_bytes, sizeof(dword.byte));

    return dword;
}

void fill_dword(Dword* dword) {
    int i;
    if (dword != NULL) {
        for (i = 0; i < dword->num_bytes; i++) {
            scanf("%hhu", &dword->byte[i]);
        }
    }
}

void flip_bit(Dword* dword, unsigned bit_dword_pos) {
    unsigned char byte_pos = bit_dword_pos / CHAR_BIT;
    unsigned char bit_pos = (1 << (bit_dword_pos % CHAR_BIT));
    if (byte_pos >= dword->num_bytes)
        return;
    else
        dword->byte[byte_pos] ^= bit_pos;
}

void free_dword(Dword* dword) {
    free(dword->byte);
    dword->byte = 0;
    dword->num_bytes = 0;
}

void print_dword(Dword* dword) {
    int i;
    for (i = 0; i < dword->num_bytes; i++) {
        printf("%hhu ", dword->byte[i]);
    }
}

int main(void) {
    int num_of_bytes = 0;
    unsigned flip_bit_pos = 0;
    scanf("%d", &num_of_bytes);
    Dword my_dword = init_dword(num_of_bytes);
    fill_dword(&my_dword);
    scanf("%u", &flip_bit_pos);
    flip_bit(&my_dword, flip_bit_pos);
    print_dword(&my_dword);
    free_dword(&my_dword);

    return 0;
}
