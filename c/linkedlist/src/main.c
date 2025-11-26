#include "list.h"
#include <stdio.h>

int main(void) {
  struct List* list = init();

  for (int i = 0; i < 100; ++i) {
    add(list, i);
  }

  reverse(list);

  print_list(list);

  insert(list, 10, 5);

  printf("%d\n", get(list, 10));
  
  return 0;
}
