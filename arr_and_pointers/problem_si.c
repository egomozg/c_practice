#include <stdio.h>
int moveright(int *arr, int key, int last);

void inssort(int *arr, int len) {
  int i;
  for (i = 0; i < len; ++i) {
    int key, pos;
    key = arr[i];
    pos = moveright(arr, key, i);
    arr[pos] = key;
  }
}

int find_pos(int *arr, int key, int last) {
	int i;
	for (i = 0; i < last; ++i) {
		if (key < arr[i]) {
			return i;
		}
	}
	return last;
}

int moveright(int *arr, int key, int last) {
	int i;
	int founded_pos = find_pos(arr, key, last);
	if (last == 0) {
		return 0;
	}
	for (i = last; i > founded_pos; --i) {
		arr[i] = arr[i - 1];
	}
	return founded_pos;
}

int main(void) {
	int i;
	int arr[6] = {1, 2, 4, 5, 3, 2};
	inssort(arr, 6);
	for (i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
