//
// not finished yet
//
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
  for (;;) {
    int res, n = 0;
    res = fscanf(inp, "%d", &n);
    if (res == EOF)
      break;
    if (res != 1) {
      continue;
    }
    node = calloc(1, sizeof(struct node_t))
    if (n % 2 == 0) {
        node->next = top_even;
        top_even = node;
    }
    else {
        node->next = top_odd;
        top_odd = node;
    }
  }
  while (node->next != NULL) {
    node = node->next;
  }
  return top_even;
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
