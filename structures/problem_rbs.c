#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#if 1
struct node_t {
  struct node_t *next;
  int data;
};
#endif

int fill_array(int *arr, const unsigned size);
void print_list(const struct node_t *top);
void fill_buckets(const int *arr, const unsigned size, struct node_t **buckets);
void delete_buckets(struct node_t **top, const unsigned size);
void print_buckets(struct node_t *const *const top, unsigned const size);
int find_max(const int *arr, int const size);

int main(void) {
  unsigned arr_size = 0;
  int i;
  if (scanf("%u", &arr_size) != 1)
    return 1;
  int *arr = (int *)calloc(arr_size, sizeof(int));
  struct node_t **buckets =
      (struct node_t **)calloc(arr_size, sizeof(struct node_t *));
  if (arr == NULL || buckets == NULL || !fill_array(arr, arr_size))
    return 1;
  for (i = 0; i < arr_size; ++i) {
    buckets[i] = (struct node_t *)calloc(1, sizeof(struct node_t));
    if (!buckets)
      return 1;
  }
  fill_buckets(arr, arr_size, buckets);
  print_buckets(buckets, arr_size);

  delete_buckets(buckets, arr_size);
  free(arr);
  arr = NULL;

  return 0;
}

int fill_array(int *arr, const unsigned size) {
  unsigned i;
  for (i = 0; i < size; ++i) {
    if (scanf("%d", &arr[i]) != 1)
      return 0;
  }
  return 1;
}

void fill_buckets(const int *arr, const unsigned size,
                  struct node_t **buckets) {
  int i;
  int bi = find_max(arr, size) / size;
  struct node_t *node;
  for (int i = 0; i < size; ++i) {
    node = (struct node_t *)calloc(1, sizeof(struct node_t));
    node->data = arr[i];
    node->next = buckets[arr[i] / bi];
    buckets[arr[i] / bi] = node;
  }
}

int find_max(const int *arr, int const size) {
  unsigned i;
  unsigned idx = 0;
  int max = arr[0];
  for (i = 0; i < size; ++i) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

void print_buckets(struct node_t *const *const top, unsigned const size) {
  int i;
  struct node_t *p;
  for (i = 0; i < size; ++i) {
    for (p = top[i]; p != NULL; p = p->next) {
      printf("%d ", p->data);
    }
  }
  printf("\n");
}
void delete_buckets(struct node_t **top, const unsigned size) {
  struct node_t *next;
  unsigned i;
  if (top == NULL) {
    printf("tried to delete nullptr\n");
    abort();
  }
  for (i = 0; i < size; ++i) {
    next = top[i];
    while (next != NULL) {
      next = next->next;
      free(top[i]);
      top[i] = next;
    }
  }
  free(top);
}

void print_list(const struct node_t *top) {
  const struct node_t *i = top;
  if (i == NULL) {
    return;
  }
  while (i != NULL) {
    printf("%d ", i->data);
    i = i->next;
  }
  printf("\n");
}
