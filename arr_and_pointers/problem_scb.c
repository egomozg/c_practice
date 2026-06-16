#include <stdlib.h>
#include <stdio.h>
typedef int (*cmp_t)(const void *lhs, const void *rhs);

///
/// @param key элемент, который ищется
/// @param base массив в котором осуществляется поиск
/// @param size это размер элементов массива (и, соответственно, элемента key)
/// @param num количество элементов в массиве
/// @param cmp компаратор
///
/// @return указатель на найденный элемент, либо NULL
///
void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp);

int int_bsearch(const void *lhs, const void *rhs);

void *cbsearch(const void *key, const void *base, int num, int size,
               cmp_t cmp) {
  const char *base_char = (const char *) base;
  const char *l = base_char;
  const char *r = base_char + size * (num - 1);
  while (l <= r) {
    const char *m = (char *)(l + size * ((r - l) / (size * 2)));
    int cmp_res = (*cmp)(m, key);
    if (cmp_res == 0)
      return (void *)m;
    else if (cmp_res < 0)
      l = m + size;
    else if (cmp_res > 0)
      r = m - size;
  }
  return NULL;
}

int int_cmp(const void *lhs, const void *rhs) {
  const int *ilhs = (const int *)lhs;
  const int *irhs = (const int *)rhs;
  if (*ilhs > *irhs)
    return 1;
  if (*ilhs < *irhs)
    return -1;
  return 0;
}

int main(void) {
  int a[6] = {1, 2, 3, 4, 5, 6};
  int key = 7;
  int* res = (int*) cbsearch(&key, a, 6, sizeof(int), int_cmp);
  if (res != NULL)
    printf("%d\n", *res);
  else
    printf("0\n");
  return 0;
}
