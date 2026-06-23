#include <stdio.h>
int majority_element(const int *parr, int len);
enum { SIZE = 8 };

int main(void) {
	int arr[SIZE] = {3, 3, 4, 2, 4, 4, 2, 4};
	int majority = majority_element(arr, SIZE);
	printf("%d\n", majority);
	return 0;
}

int majority_element(const int *parr, int len) {
	unsigned long long i;
	int count = 0;
	int candidate = parr[0];
	for (i = 1; i < len; ++i) {
		if (parr[i] == candidate)
			count++;
		else if (parr[i] != candidate && count == 0)
			candidate = parr[i];
		else
			count--;
	}
	count = 0;
	for (i = 0; i < len; ++i) {
		if (parr[i] == candidate)
			count++;
	}
	if (count > len / 2)
		return candidate;
	else
		return -1; // no majority
}
