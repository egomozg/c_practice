#include <stdio.h>
#include <stdlib.h>

unsigned linear_search(int const *parr, unsigned len, int elem);
void swap(unsigned *v1, unsigned *v2);
void selsort(int *arr, unsigned len);
unsigned find_min(int const *arr, int const size);
int fill_array(int *arr, unsigned const size);
void print_array(int const *arr, unsigned const size);

int main(void) {
  int n = 0;
  unsigned i;
  unsigned last_pos;
  if (scanf("%u", &n) != 1)
    return 1;
  int *arr = (int *)malloc(n * sizeof(int));
  if (arr == NULL)
    return 1;
  if (!fill_array(arr, n)) {
    free(arr);
    return 1;
  }
  if (scanf("%u", &last_pos) != 1) {
    free(arr);
    return 1;
  }
	// printf("%d", arr[last_pos]);
  selsort(arr + last_pos, n - last_pos);
  print_array(arr, n);

  free(arr);
  return 0;
}

unsigned find_min(int const *arr, int const size) {
  unsigned i;
  unsigned idx = 0;
  int min = arr[0];
  for (i = 0; i < size; ++i) {
    if (min > arr[i]) {
      min = arr[i];
    }
  }
  return min;
}

unsigned linear_search(int const *parr, unsigned len, int elem) {
  unsigned i;
  for (i = 0; i < len; ++i)
    if (parr[i] == elem)
      return i;
  return len;
}
void swap(unsigned *v1, unsigned *v2) {
  unsigned tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}

void selsort(int *arr, unsigned len) {
  unsigned min = find_min(arr, len);
  unsigned min_idx = linear_search(arr, len, min);
  if (arr[0] == min_idx)
    return;
  swap((unsigned *)arr, (unsigned *)arr + min_idx);
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
