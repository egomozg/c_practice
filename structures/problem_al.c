//
// not finished yet, not tested yet
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
struct node_t *create_list();
void delete_list(struct node_t *top);
int emplace(struct node_t *node, const int data);

struct node_t *create_list() {
  struct node_t *top = (struct node_t *)calloc(1, sizeof(struct node_t));
  top->next = (struct node_t *)calloc(1, sizeof(struct node_t));
  return top;
}

int emplace(struct node_t *top, const int data) {
  struct node_t *current = top;
  while (current->next != NULL)
    current->next = current->next->next;
  current->next->data = data;
  current->next->next = (struct node_t *)calloc(1, sizeof(struct node_t));
  if (current->next->next == NULL) return 0; //failure
  return 1; //success
}

struct node_t *read_list(FILE *inp) {
  struct node_t *top_even = create_list();
  struct node_t *top_odd = create_list();
  struct node_t *iterable = top_even;
  if (!top_even || !top_odd) {
    return NULL;
  }
	for (;;) {
		int res, n = 0;
		res = fscanf(inp, "%d", &n);
		if (res == EOF)
			break;
		if (res != 1) {
			fprintf(stderr, "File have broken format\n");
			abort();
		}
    if (n % 2 == 0)
      emplace(top_even, n);
    else
      emplace(top_odd, n);
	}
  while (iterable != NULL) {
    iterable = iterable->next;
  }
  iterable = top_odd;
  return top_even;
}

void delete_list(struct node_t *top) {
  struct node_t *next = top;
  while (next != NULL) {
    next = next->next;
    free(top);
    top = next;
  }
}
