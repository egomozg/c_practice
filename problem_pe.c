#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
  int n;
  unsigned char *s;
};

void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned n);

void fill_sieve(struct sieve_t *sv)
{
    unsigned long long n_bits = sv->n * CHAR_BIT;
    for (unsigned long long i = 2; i * i < n_bits; ++i) {
        unsigned byte = i / CHAR_BIT;
        unsigned n_pos = i % CHAR_BIT;
        unsigned shift = CHAR_BIT - 1 - n_pos;
        if ((sv->s[byte] >> shift) & 1u)
            continue;
        for (unsigned long long j = i; j * i < n_bits; ++j) {
            byte = (j * i) / CHAR_BIT;
            n_pos = (j * i) % CHAR_BIT;
            shift = CHAR_BIT - 1 - n_pos;
            sv->s[byte] |= (1u << shift);
        }
    }
}

int is_prime(struct sieve_t* sv, unsigned n)
{
    unsigned byte = n / CHAR_BIT;
    unsigned n_pos = n % CHAR_BIT;
    unsigned shift = CHAR_BIT - 1 - n_pos;
    assert(n < sv->n * CHAR_BIT);
    return ((sv->s[byte] >> shift) & 1) ? 0 : 1;
}

void print_sieve(struct sieve_t* sv)
{
    for (int i = 2; i < sv->n * CHAR_BIT; i++)
    {
        unsigned byte = i / CHAR_BIT;
        unsigned n_pos = i % CHAR_BIT;
        unsigned shift = CHAR_BIT - 1 - n_pos;
        ((sv->s[byte] >> shift) & 1) ? printf("0 ") : printf("1 ");
    }
    printf("\n");
}

struct sieve_t init_sieve(unsigned n)
{
    struct sieve_t s;
    s.n = n + 1;
    s.s = calloc(s.n, sizeof(char));

    return s;
}

void free_sieve(struct sieve_t* s)
{
    free(s->s);
    s->s = 0;
    s->n = 0;
}

int main(void)
{
    int n = 0;
    struct sieve_t s = init_sieve(100);
    fill_sieve(&s);
    if (s.s != NULL && s.n > 0) {
        #if 1
        print_sieve(&s);
        #endif
        free_sieve(&s);
    }

    return 0;
}
