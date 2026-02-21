#include "binary_tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Node create_node(int value) {
  Node node;
  node.value = value;
  return node;
}

Tree bt_init() {
  Tree tree;
  tree.root = NULL;
  return tree;
}

void bt_add(Tree *tree, int val) {
  if (!tree)
    return;

  Node *node = malloc(sizeof(Node));
  node->value = val;

  if (!tree->root) {
    tree->root = node;
    return;
  }

  Node *curr = tree->root;

  while (true) {
    if (curr->value == val)
      return;
    else if (val < curr->value) {
      if (curr->left == NULL) {
        curr->left = node;
        return;
      }
      curr = curr->left;
    } else {
      if (curr->right == NULL) {
        curr->right = node;
        return;
      }
      curr = curr->right;
    }
  }
}

void rec_bt_print_helper(Node *node, int level) {
  if (!node) return;
  
  rec_bt_print_helper(node->right, level + 1);

  for (int i = 0; i < level; i++) printf("  ");
  printf("%d\n", node->value);

  rec_bt_print_helper(node->left, level + 1);
}

void rec_bt_print(Tree *tree) {
  if (!tree || !tree->root)
    return;

  rec_bt_print_helper(tree->root, 0);
  printf("\n");
}
