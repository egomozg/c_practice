//
// подсмотренное решение, даже поленился
// итеративный reverse написать
//
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#if 1
struct node_t {
  struct node_t *next;
  int data;
};
#endif

struct node_t *read_list(FILE *inp);
void delete_list(struct node_t *top);
void print_list(const struct node_t *top);
struct node_t * reverse(struct node_t *top);

int main(void) {
  FILE *f;
  int count = 0;

  f = fopen("test.txt", "r");
  if (!f) {
    perror("Error opening file");
    return 1;
  }
  struct node_t *al = read_list(f);
  print_list(al);
  delete_list(al);

  return 0;
}

struct node_t *read_list(FILE *inp) {
  struct node_t *top_even = NULL, *top_odd = NULL, *node;
  struct node_t *last_odd = NULL;
  for (;;) {
    int res, n = 0;
    res = fscanf(inp, "%d", &n);
    if (res == EOF)
      break;
    if (res != 1) {
      continue;
    }
    node = (struct node_t *)calloc(1, sizeof(struct node_t));
    node->data = n;
    if (n % 2 == 0) {
      node->next = top_even;
      top_even = node;
    } else {
      if (top_odd == NULL)
        last_odd = node;
      node->next = top_odd;
      top_odd = node;
    }
  }
  if (last_odd == NULL)
      return reverse(top_even);
  assert((last_odd->next) == NULL);
  last_odd->next = top_even;
  return reverse(top_odd);
}

void delete_list(struct node_t *top) {
  if (top == NULL) {
    printf("tried to delete nullptr\n");
    abort();
  }
  struct node_t *next = top;
  while (next != NULL) {
    next = next->next;
    free(top);
    top = next;
  }
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

struct node_t * reverse(struct node_t *top) {
    struct node_t *xs;
    if (NULL == top) return NULL;
    if (NULL == top->next) return top;
    xs = reverse(top->next);
    top->next->next = top;
    top->next = NULL;
    return xs;
}
