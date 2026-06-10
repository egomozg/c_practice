#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

struct sieve_t {
    unsigned long long size;
    unsigned char* sieve;
};

struct sieve_t init_sieve(unsigned n);
unsigned is_prime(struct sieve_t s, unsigned n);
void free_sieve(struct sieve_t* s);
unsigned long long count_prime_number(struct sieve_t s);
void print_sieve(struct sieve_t s);

int main()
{
    int n = 0;
    int res = 0;
    res = scanf("%d", &n);
    assert(res == 1);
    struct sieve_t s = init_sieve(n);
    assert(s.sieve != NULL && s.size > 0);
    unsigned long long amount_of_prime_numbers = count_prime_number(s);
    #if 1
    print_sieve(s);
    #endif
    free_sieve(&s);
    printf("%llu", amount_of_prime_numbers);

    return 0;
}

struct sieve_t init_sieve(unsigned n)
{
    struct sieve_t s;
    s.size = n + 1;
    s.sieve = calloc(s.size, sizeof(char));

    for (unsigned long long i = 2; i < s.size; i++)
    {
        if (s.sieve[i] == 1)
            continue;
        for (unsigned long long j = i; j * i < s.size; j++)
        {
            s.sieve[j * i] = 1;
        }
    }

    return s;
}

unsigned long long count_prime_number(struct sieve_t s)
{
    unsigned long long counter = 0;
    for (int i = 2; i < s.size; i++)
    {
        if (s.sieve[i] == 0) counter++;
    }

    return counter;
}

void print_sieve(struct sieve_t s)
{
    for (int i = 2; i < s.size; i++)
    {
        (s.sieve[i] == 0) ? printf("1 ") : printf("0 ");
    }
}

unsigned is_prime(struct sieve_t s, unsigned n)
{
    assert(n < s.size);
    return (s.sieve[n] == 1) ? 0 : 1;
}

void free_sieve(struct sieve_t* s)
{
    free(s->sieve);
    s->sieve = 0;
    s->size = 0;
}
