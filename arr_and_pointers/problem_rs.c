#include <stdlib.h>
#include <stdio.h>

int fill_array(int *arr, unsigned const size);
void bucket_exclusive_scan(int *bucket, const int size);
void radix(int *arr, const int size, const int expn);
void print_array(int const *arr, unsigned const size);
int powi(int base, int exp);

int main(void) {
  int size = 0;
	int rank = 0;
  unsigned i;
  if (scanf("%u", &size) != 1)
    return 1;
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL)
    return 1;
  if (!fill_array(arr, size)) {
    free(arr);
    return 1;
  }
  if (scanf("%u", &rank) != 1)
    return 1;
	// printf("%d", arr[last_pos]);
	radix(arr, size, rank);
  print_array(arr, size);

  free(arr);
	arr = NULL;

  return 0;
}

int powi(int base, int exp) {
  if (exp == 0)
    return 1;
  int mult = base;
  int prod = 1;
  while (exp > 0) {
    if ((exp % 2) == 1)
      prod = (prod * mult);
    mult = (mult * mult);
    exp /= 2;
  }

  return prod;
}

void print_array(int const *arr, unsigned const size) {
  unsigned i;
  for (i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
}

int fill_array(int *arr, unsigned const size) {
  unsigned i;
  for (i = 0; i < size; ++i) {
    if (scanf("%d", &arr[i]) != 1)
      return 0;
  }
  return 1;
}

void bucket_exclusive_scan(int *bucket, const int size) {
  unsigned long long j;
	int temp = bucket[0];
	int sum = temp;
	bucket[0] = 0;
  for (j = 1; j < size; j++) {
		temp = bucket[j];
		bucket[j] = sum;
		sum += temp;
  }
}

void radix(int *arr, const int size, const int rank) {
  int expn = powi(10, rank);
  unsigned long long j;
  int b[10] = {0};
  for (j = 0; j < size; ++j)
    b[(arr[j] / expn) % 10] += 1;
  bucket_exclusive_scan(b, 10);
  int *c = (int *)calloc(size, sizeof(int));
  if (c == NULL)
    return;
  for (j = 0; j < size; ++j) {
    c[b[(arr[j] / expn) % 10]] = arr[j];
    b[(arr[j] / expn) % 10]++;
  }
	for (j = 0; j < size; ++j) {
		arr[j] = c[j];
	}
	free(c);
	c = NULL;
}

