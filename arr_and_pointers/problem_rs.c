void radix(int *arr, const int size) {
	int expn = 1;
	unsigned long long j;
	int b[10] = {0};
	for (j = 0; j < size; ++j)
		b[(arr[j] / expn) % 10] += 1;
	for (j = 1; j < 10; ++j)
		b[j] += b[j - 1];
	// TODO: дорешать

	expn *= 10;
}
