#pragma once

struct Element {
  struct Element *next;
  int value;
};

struct List {
  struct Element *head;
  unsigned long size;
};

void print_list(struct List *list);
struct List *init();
void add(struct List *list, int val);
void remove_val(struct List *list, int val);
void reverse(struct List *list);
int get(struct List *list, unsigned long index);
_Bool includes(struct List *list, int val);
void insert(struct List *list, unsigned long index, int val);
