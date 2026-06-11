#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void fill_array(int *arr, const int size) {
  int i;
  for (i = 0; i < size; ++i) {
    if (scanf("%d", &arr[i]) == 1) {
    } else
      printf("wrong input\n");
  }
}

void find_min_max(const int *arr, const int size) {
  int i;
  int min = INT_MAX;
  int max = INT_MIN;
  for (i = 0; i < size; ++i) {
    if (min > arr[i])
      min = arr[i];
    if (max < arr[i])
      max = arr[i];
  }
  printf("%d %d", min, max);
}

int main(void) {
  int n;
  int i;
  if (scanf("%d", &n) == 1) {
    int *arr = (int *) calloc(n, sizeof(int));
    fill_array(arr, n);
    find_min_max(arr, n);
		free(arr);
  }

  return 0;
}
