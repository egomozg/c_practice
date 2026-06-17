#include <stdio.h>
#include <string.h>
typedef int (*cmp_t)(void const *lhs, void const *rhs);

int int_cmp(const void *lhs, const void *rhs);
int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp);
void *find_min(const void *arr, int eltsize, int numelts, cmp_t cmp);
void swap(void *v1, void *v2, int eltsize);

int main(void) {
  int a[9] = {1, 2, 3, 4, 5, 8, 6, 7, 9};
  int last_pos = 5;
  unsigned i;
  printf("%d\n", selstep(a, sizeof(int), 9, last_pos, int_cmp));
  for (i = 0; i < 9; ++i) {
    printf("%d ", a[i]);
  }
  return 0;
}

int int_cmp(const void *lhs, const void *rhs) {
  const int *ilhs = (const int *)lhs;
  const int *irhs = (const int *)rhs;
  if (*ilhs > *irhs)
    return -1;
  if (*ilhs < *irhs)
    return 1;
  return 0;
}

void *find_min(const void *arr, int eltsize, int numelts, cmp_t cmp) {
  const char *min = (const char *)arr;
  const char *carr = min;
  unsigned i;
  for (i = 0; i < numelts; ++i) {
    if (cmp(carr + i * eltsize, min) == 1) {
      min = carr + i * eltsize;
    }
  }
  return (void *)min;
}

void swap(void *v1, void *v2, int eltsize) {
  char buf[eltsize];

  memcpy(buf, v1, eltsize);
  memcpy(v1, v2, eltsize);
  memcpy(v2, buf, eltsize);
}

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
  char *carr = (char *)parr + 1 * eltsize * nsorted;
  void *min = find_min(carr, eltsize, numelts - nsorted, cmp);
  swap((void *)carr, (void *)min, eltsize);
  return 0;
}
