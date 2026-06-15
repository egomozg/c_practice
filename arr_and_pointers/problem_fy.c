#include <stdio.h>
#include <stdlib.h>

int myrand();
int fill_array(int *arr, const int size);
void shuffle_array(int *arr, const int size);
void print_array(const int *arr, const int size);

int main(void) {
  int n;
  int i;
  if (scanf("%d", &n) == 1) {
    int *arr = (int *)calloc(n, sizeof(int));
    if (!arr) {
      printf("error allocating memory\n");
      return 1;
    }
    if (fill_array(arr, n)) {
      shuffle_array(arr, n);
      print_array(arr, n);
    } else {
      printf("0\n");
    }
		free(arr);
		arr = NULL;
  }

  return 0;
}

int fill_array(int *arr, const int size) {
  int i;
  if (size == 0)
    return 0;
  for (i = 0; i < size; ++i) {
    if (scanf("%d", &arr[i]) == 1) {
    } else
      printf("wrong input\n");
  }
	return 1;
}

int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

void shuffle_array(int *arr, const int size) {
  int i;
  for (i = size - 1; i > 0; --i) {
    int switch_pos = myrand() % (i + 1);
    int temp = arr[switch_pos];
    arr[switch_pos] = arr[i];
    arr[i] = temp;
  }
}

void print_array(const int *arr, const int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
	printf("\n");
}
