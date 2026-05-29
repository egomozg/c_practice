#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct sieve_t {
    int n;
    char* s;
};

void fill_sieve(struct sieve_t *sv);
int nth_prime(struct sieve_t *sv, int N);

void free_sieve(struct sieve_t* s);
unsigned long long count_prime_number(struct sieve_t s);
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
    unsigned long long amount_of_prime_numbers = count_prime_number(s);
    #if 1
    print_sieve(s);
    #endif
    free_sieve(&s);
    printf("%llu", amount_of_prime_numbers);

    return 0;
}

void fill_sieve(struct sieve_t *sv)
{
    for (unsigned long long i = 2; i * i < sv->n; i++) {
        if (sv->s[i] == 1)
            continue;
        for (unsigned long long j = i; j * i < sv->n; j++) {
            sv->s[j * i] = 1;
        }
    }
}

int nth_prime(struct sieve_t *sv, int N) {
    int return_value = 0;
    for (int i = 2; i < sv->n; i++) {
        if (sv->s[i] == 0 && --N > 0) {
            continue;
        } else if (sv->s[i] == 1) {
            continue;
        } else {
            return_value = i;
        }
    }

    return return_value;
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


void free_sieve(struct sieve_t* s)
{
    free(s->s);
    s->s = 0;
    s->n = 0;
}

int sieve_bound(unsigned num) {
    assert(num > 20);
    double dnum = num;
    double dres = dnum * (log(dnum) + log(log(dnum)));
    return (unsigned long long) round(dres);
}
