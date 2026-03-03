#include "double_linked_list.h"

int main(void) {
  List list;

  for (int i = 0; i < 20; ++i) {
    add(&list, i);
  }
  
  print2(&list);

  for (int i = 0; i < 20; ++i) {
  dll_remove(&list, 0);
  }

  print2(&list);

  return 0;
}
