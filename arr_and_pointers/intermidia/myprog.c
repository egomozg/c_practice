#include <stdio.h>
#include <stdlib.h>

int find_in_file(const char *filename, int needle) {
	FILE *f;
	int count = 0;

	f = fopen(filename, "r");
	if (!f) {
		perror("Error opening file");
		abort();
	}

	for (;;) {
		int res, n = 0;
		res = fscanf(f, "%d", &n);
		if (res == EOF)
			break;
		if (res != 1) {
			fprintf(stderr, "File %s have broken format\n", filename);
			abort();
		}
		if (needle == n)
			count += 1;
	}

	fclose(f);
	return count;
}

int main(int argc, char **argv) {
	int n, i, count = 0; char *endptr;
	if (argc < 3) {
		fprintf(stderr, "Call: %s <n> <files...>\n", argv[0]);
		return 1;
	}

	n = strtol(argv[1], &endptr, 10);
	if (endptr == argv[1]) {
		fprintf(stderr, "<%s> cannot be converted to integer\n", argv[1]);
		return 1;
	}

	for (i = 2; i < argc; ++i)
		count += find_in_file(argv[i], n);

	printf("%d\n", count);
}
