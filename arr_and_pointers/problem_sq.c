#include <assert.h>
#include <stdio.h>
#define SIZE 10

void qsort_impl(int *arr, unsigned low, unsigned high);
void qsort(int *arr, unsigned len);
void swap(int *v1, int *v2);
unsigned partition(int *arr, unsigned low, unsigned high);

int main(void) {
  int i;
  int arr[SIZE] = {5, 6, 8, 4, 5, 6, 3, 8, 1, 2};
  // printf("%d\n", partition(arr, 0u, SIZE - 1));
  qsort(arr, SIZE);
  for (i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  return 0;
}

void swap(int *v1, int *v2) {
  int tmp = *v1;
  *v1 = *v2;
  *v2 = tmp;
}


// 
// at first I thought that this partition looks so ugly
// cuz when I tried google qsort visualization I saw much smaller
// and simpler code, when I started look closer to this code I noticed
// that it doing some unnecessary swaps and it's not optimized. Turns out
// this was Lomuto scheme and it has these quirks I noticed, and mine was
// Hoare which is more efficient in reality. Also my code use first element
// as pivot, but it's more reasonable to select pivot somewhere in between
// array.
// TODO: study on pivot selection
//
unsigned partition(int *arr, unsigned low, unsigned high) {
  unsigned first = low;
  int pivot = arr[first];
  low++;
  while (low < high) {
    if (arr[low] <= pivot) {
      low++;
      continue;
    }
    if (arr[high] > pivot) {
      high--;
      continue;
    }
    assert(arr[low] > arr[high]);
    swap(arr + low, arr + high);
		low++;
		high--;
  }
	if (low == high && arr[low] <= pivot) {
		swap(arr + first, arr + high);
		return high;
	}
	if (low == high && arr[low] > pivot) {
		swap(arr + first, arr + --high);
		return high;
	}
  swap(arr + first, arr + high);
  return high;
}

void qsort_impl(int *arr, unsigned low, unsigned high) {
  if (low >= high)
    return;
  unsigned pi = partition(arr, low, high);
#if 1
  printf("%d\n", pi);
#endif
  if (pi > low)
    qsort_impl(arr, low, pi - 1);
  qsort_impl(arr, pi + 1, high);
}

void qsort(int *arr, unsigned len) { qsort_impl(arr, 0u, len - 1); }
