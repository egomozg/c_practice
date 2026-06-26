#include <stdio.h>
#include <stdlib.h>

int fill_array(int *arr, unsigned const size);
void fill_bucket(int *bucket, unsigned const bucket_size, const int *arr,
                 unsigned const arr_size);
unsigned find_max(const int *arr, const int size);
void print_array(const int *arr, unsigned const size);

int main(void) {
  int size = 0;
  if (scanf("%d", &size) != 1)
    return 1;

  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("memory error\n");
    return 1;
  }
  fill_array(arr, size);

  unsigned bucket_size = find_max(arr, size) + 1;
  int *bucket = (int *)calloc(bucket_size, sizeof(int));
  if (bucket == NULL) {
    printf("memory error\n");
    return 1;
  }
	fill_bucket(bucket, bucket_size, arr, size);
    print_array(bucket, bucket_size);

	free(arr);
	free(bucket);
	arr = NULL;
	bucket = NULL;

	return 0;
}

int fill_array(int *arr, unsigned const size) {
  unsigned i;
  for (i = 0; i < size; ++i) {
    if (scanf("%d", &arr[i]) != 1)
      return 0;
  }
  return 1;
}

unsigned find_max(const int *arr, const int size) {
  unsigned i;
  unsigned idx = 0;
  int max = arr[0];
  for (i = 0; i < size; ++i) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

void fill_bucket(int *bucket, unsigned const bucket_size, const int *arr,
                 unsigned const arr_size) {
  unsigned long long i;
  for (i = 0; i < arr_size; ++i) {
    bucket[arr[i]]++;
  }
}

void print_array(int const *arr, unsigned const size) {
  unsigned i;
  for (i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
}
