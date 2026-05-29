#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct sieve_t {
    unsigned long long n;
    unsigned char* s;
};

struct sieve_t init_sieve(unsigned n);
unsigned is_prime(struct sieve_t s, unsigned n);
void free_sieve(struct sieve_t* s);
unsigned long long count_prime_number(struct sieve_t s);
unsigned long long nth_prime(struct sieve_t *sv, int N);
void print_sieve(struct sieve_t s);
int sieve_bound(unsigned num);

int main()
{
    int n = 0;
    int res = 0;
    res = scanf("%d", &n);
    assert(res == 1);
    struct sieve_t s = init_sieve(n);
    assert(s.s != NULL && s.n > 0);
    unsigned long long prime = nth_prime(&s, n);
    #if 1
    print_sieve(s);
    #endif
    free_sieve(&s);
    printf("%llu", prime);

    return 0;
}

struct sieve_t init_sieve(unsigned n)
{
    struct sieve_t s;
    s.n = sieve_bound(20 + n);
    s.s = calloc(s.n, sizeof(char));

    for (unsigned long long i = 2; i < s.n; i++)
    {
        if (s.s[i] == 1)
            continue;
        for (unsigned long long j = i; j * i < s.n; j++)
        {
            s.s[j * i] = 1;
        }
    }

    return s;
}

unsigned long long count_prime_number(struct sieve_t s)
{
    unsigned long long counter = 0;
    for (int i = 2; i < s.n; i++)
    {
        if (s.s[i] == 0) counter++;
    }

    return counter;
}

void print_sieve(struct sieve_t s)
{
    for (int i = 2; i < s.n; i++)
    {
        (s.s[i] == 0) ? printf("0 ") : printf("1 ");
    }
    printf("\n");
}

unsigned is_prime(struct sieve_t s, unsigned n)
{
    assert(n < s.n);
    return (s.s[n] == 1) ? 0 : 1;
}

void free_sieve(struct sieve_t* s)
{
    free(s->s);
    s->s = 0;
    s->n = 0;
}


void fill_sieve(struct sieve_t *sv)
{
    for (unsigned long long i = 2; i < sv->n; i++) {
        if (sv->s[i] == 1)
            continue;
        for (unsigned long long j = i; j * i < sv->n; j++) {
            sv->s[j * i] = 1;
        }
    }
}

unsigned long long nth_prime(struct sieve_t *sv, int N) {
    int return_value = 0;
    for (unsigned long long i = 2; i < sv->n; i++) {
        if (sv->s[i] == 0 && --N > 0) {
            continue;
        } else if (sv->s[i] == 1) {
            continue;
        } else {
            return_value = i;
            break;
        }
    }

    return return_value;
}

int sieve_bound(unsigned num) {
    assert(num > 20);
    double dnum = num;
    double dres = dnum * (log(dnum) + log(log(dnum)));
    return (unsigned long long) round(dres);
}
