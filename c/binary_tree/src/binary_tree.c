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

void rec_bt_print_helper(Node *node) {
  if (node->left)
    rec_bt_print_helper(node->left);
  printf("%d", node->value);
  if (node->right)
    rec_bt_print_helper(node->right);
}

void rec_bt_print(Tree *tree) {
  if (!tree || !tree->root)
    return;

  rec_bt_print_helper(tree->root);
  printf("\n");
}
