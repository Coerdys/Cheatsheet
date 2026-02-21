#include "binary_tree.h"

#include <stdio.h>

int main(void) {
  Tree tree = bt_init();
  int arr[] = {3, 5, 7, 4, 9, 0, 2, 1, 6, 8};
  char c[5];
  sprintf(c, "%d", 1);
  printf("%s", c);
  
  for (int i = 0; i < 10; ++i) {
    bt_add(&tree, arr[i]);
  }

  rec_bt_print(&tree);

  return 0;
}
