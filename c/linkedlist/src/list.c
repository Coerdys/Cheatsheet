#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_list(struct List *list) {
  struct Element *curr = list->head;

  size_t str_len = 4; // 2 for "[" and "]\n\0" at the end

  for (curr = list->head; curr != NULL; curr = curr->next) {
    str_len += snprintf(NULL, 0, "%d", curr->value); // len of number

    if (curr->next != NULL) {
      str_len += 2; // 2 more len for ", "
    }
  }

  char str[str_len];
  str[0] = '[';

  size_t ctr = 1;

  for (curr = list->head; curr != NULL; curr = curr->next) {
    char temp[11 + 1]; // 11 because of max int size: "-2147483648\0"

    int len = snprintf(temp, 11 + 1, "%d", curr->value);

    strncpy(str + ctr, temp, len);
    ctr += len;

    if (curr->next != NULL) {
      strncpy(str + ctr, ", ", 2);
      ctr += 2;
    }
  }

  str[str_len - 3] = ']';
  str[str_len - 2] = '\n';
  str[str_len - 1] = '\0';

  printf("%s\n", str);
}

struct List *init() {
  struct List *list = (struct List *)malloc(sizeof(struct List));

  if (list == NULL) {
    fprintf(stderr, "Could not malloc to init list\n");
    exit(1);
  }

  list->head = NULL;
  list->size = 0;

  return list;
}

void add(struct List *list, int val) {
  struct Element *head = list->head;

  if (head == NULL) {
    head = (struct Element *)malloc(sizeof(struct Element));

    if (head == NULL) {
      goto error_handling;
    }

    head->value = val;

    list->head = head;
    list->size++;
    return;
  } else {
    struct Element *curr = head;

    while (curr->next != NULL) {
      curr = curr->next;
    }

    curr->next = (struct Element *)malloc(sizeof(struct Element));

    if (curr->next == NULL) {
      goto error_handling;
    }

    curr->next->value = val;
    list->size++;
    return;
  }

error_handling:
  fprintf(stderr, "Could not malloc for %d\n", val);
  exit(1);
}

void insert(struct List* list, size_t index, int val) {
  if (index >= list->size || index < 0) {
    fprintf(stderr, "Tried inserting into position %lu but list only has length %lu\n", index, list->size);
    return;
  } else {
    struct Element* curr = list->head;
    index--;

    while (index-- > 0) {
      curr = curr->next;
    }

    printf("%d\n", curr->value);
  }
}

void remove_val(struct List *list, int val) {
  struct Element *head = list->head;

  if (head == NULL) {
    fprintf(stderr, "Tried to remove from empty list!\n");
  } else if (head->value == val) {
    struct Element *temp = list->head;
    list->head = head->next;
    free(temp);
    list->size--;
  } else {
    struct Element *curr;
    struct Element *parent = head;

    for (curr = head->next; curr != NULL; curr = curr->next) {
      if (curr->value == val) {
        parent->next = curr->next;
        free(curr);
        list->size--;
        return;
      }
      parent = curr;
    }

    fprintf(stderr, "Item %d not found!\n", val);
  }
}

void reverse(struct List *list) {
  struct Element *head = list->head;

  if (head == NULL) {
    fprintf(stderr, "Tried reversing an empty list!\n");
  } else {
    struct Element *temp;
    struct Element *parent = NULL;
    struct Element *curr = head;

    for (curr = head; curr != NULL; curr = temp) {
      temp = curr->next;
      curr->next = parent;
      parent = curr;
      curr = temp;
    }

    list->head = parent;
  }
}

_Bool includes(struct List *list, int val) {
  struct Element *curr;

  for (curr = list->head; curr != NULL; curr = curr->next) {
    if (curr->value == val) {
      return 1;
    }
  }

  return 0;
}

int get(struct List *list, unsigned long index) {
  if (index >= list->size || index < 0) {
    fprintf(stderr, "%lu not in list of length %lu\n", index, list->size);
    exit(1);
  }

  unsigned long i = 0;

  struct Element *curr;

  for (curr = list->head; curr != NULL; curr = curr->next) {
    if (i++ == index) {
      return curr->value;
    }
  }

  printf("List not long enough for index %lu\n", index);
  exit(1);
}
