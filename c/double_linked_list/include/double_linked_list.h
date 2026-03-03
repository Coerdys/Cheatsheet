#pragma once

typedef struct Node {
  struct Node *prv;
  struct Node *nxt;
  int value;
} Node;

typedef struct List {
  struct Node *root;
  int size;
} List;

void add(List *list, int value);
void dll_remove(List *list, int value);
void clear(List *list);

void print(List *list);
void print2(List *list);
