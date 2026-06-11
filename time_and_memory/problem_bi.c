#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
typedef struct dword_t {
    int num_bytes;
    unsigned char* byte;
} Dword;

int init_dword(Dword *dword, int num_bytes) {
    if (dword == NULL || num_bytes <= 0)
            return 0;

    dword->byte = calloc((size_t)num_bytes, sizeof(*dword->byte));
    if (dword->byte == NULL)
        return 0;

    dword->num_bytes = num_bytes;
    return 1;
}

int fill_dword(Dword* dword) {
    if (dword == NULL || dword->byte == NULL)
            return 0;
    for (int i = 0; i < dword->num_bytes; i++) {
            if (scanf("%hhu", &dword->byte[i]) != 1)
                return 0;
        }
    return 1;
}

void flip_bit(Dword* dword, unsigned bit_dword_pos) {
    unsigned char byte_pos = bit_dword_pos / CHAR_BIT;
    unsigned char bit_pos = (1 << (bit_dword_pos % CHAR_BIT));
    if (byte_pos >= dword->num_bytes || dword == NULL)
        return;
    else
        dword->byte[byte_pos] ^= bit_pos;
}

void free_dword(Dword* dword) {
    if (dword != NULL) {
        free(dword->byte);
        dword->byte = 0;
        dword->num_bytes = 0;
    }
}

void print_dword(Dword* dword) {
    if (dword == NULL || dword->byte == NULL)
        return;
    int i;
    for (i = 0; i < dword->num_bytes; i++) {
        printf("%hhu ", dword->byte[i]);
    }
}

int main(void) {
    int num_of_bytes = 0;
    unsigned flip_bit_pos = 0;

    if (scanf("%d", &num_of_bytes) != 1) {
        fprintf(stderr, "Ошибка чтения num_of_bytes\n");
        return 1;
    }

    Dword my_dword;
    if (!init_dword(&my_dword, num_of_bytes)) {
        fprintf(stderr, "Ошибка инициализации dword\n");
        return 1;
    }

    if (!fill_dword(&my_dword)) {
        fprintf(stderr, "Ошибка заполнения dword\n");
        free_dword(&my_dword);
        return 1;
    }

    if (scanf("%u", &flip_bit_pos) != 1) {
        fprintf(stderr, "Ошибка чтения позиции бита\n");
        free_dword(&my_dword);
        return 1;
    }

    flip_bit(&my_dword, flip_bit_pos);
    print_dword(&my_dword);
    free_dword(&my_dword);

    return 0;
}
