#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int l, int m, int r);

void swap(int *v1, int *v2) {
  int tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}

void merge_sort_imp(int *arr, int l, int r) {
  if (l >= r)
    return;
  int m = (l + r) / 2;
  merge_sort_imp(arr, l, m);
  merge_sort_imp(arr, m + 1, r);
  merge(arr, l, m, r);
}

void merge_sort(int *arr, int n) { merge_sort_imp(arr, 0, n - 1); }

void merge(int *arr, int l, int m, int r) {
	unsigned long long i;
	unsigned long long left_idx;
	unsigned long long right_idx;
	int pivot;
  if (l >= r && arr[r] > arr[l]) {
    swap(arr + l, arr + r);
  }
	int *buf = (int *) calloc(r - l + 1, sizeof(int));
	if (buf == NULL) {
		printf("error\n");
		return;
	}
	for (left_idx = l; left_idx < m; ++left_idx) {
		right_idx = left_idx + m;
		arr[left_idx] < arr[right_idx] ? buf[left_idx] = arr[left_idx] : buf[left_idx] = arr[right_idx];
	}
}
