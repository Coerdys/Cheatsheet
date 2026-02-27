#include "binary_tree.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

// Private helper functions

void check_tree(Tree *tree) {
  if (!tree) {
    perror("Tried to do operation on not initialized tree\n");
    exit(1);
  }
}

// Gets parent node of requested value
// Returns NULL if tree does not contain value
Node *bt_get_parent(Tree *tree, int val) {
  check_tree(tree);

  Node *curr = tree->root;
  if (!curr)
    return NULL;

  while (true) {
    if (val < curr->value) {
      if (!curr->left)
        return NULL;
      else if (curr->left->value == val)
        return curr;
      else
        curr = curr->left;
    } else if (val > curr->value) {
      if (!curr->right)
        return NULL;
      else if (curr->right->value == val)
        return curr;
      else
        curr = curr->right;
    } else {
      return NULL;
    }
  }
}

// Returns node of requested value
// or NULL if tree does not contain value
Node *bt_get_node(Tree *tree, int val) {
  check_tree(tree);

  Node *curr = bt_get_parent(tree, val);

  if (!curr)
    return NULL;

  if (val < curr->value) {
    return curr->left;
  } else {
    return curr->right;
  }
}

int bt_get_max_helper(Node *node) {
  if (!node) {
    perror("Tried to get max of non existent node");
    exit(1);
  }

  Node *curr = node;

  while (true) {
    if (curr->right)
      curr = curr->right;
  }

  return curr->value;
}

int bt_get_min_helper(Node *node) {
  if (!node) {
    perror("Tried to get min of non existent node");
    exit(1);
  }

  Node *curr = node;

  while (true) {
    if (curr->left)
      curr = curr->left;
  }

  return curr->value;
}

void bt_print_helper(Node *node, int level) {
  if (!node)
    return;

  bt_print_helper(node->left, level + 1);

  for (int i = 0; i < level; i++)
    printf("|  ");
  printf("|- %d\n", node->value);

  bt_print_helper(node->right, level + 1);
}

// Public use functions

Tree bt_init() {
  Tree tree;
  tree.root = NULL;
  return tree;
}

int bt_max(Tree *tree) {
  check_tree(tree);
  bt_get_max_helper(tree->root);
}

bool bt_contains(Tree *tree, int val) {
  check_tree(tree);
  return bt_get_parent(tree, val) ? true : false;
}

// Adds value to tree.
// Does not add duplicates.
void bt_add(Tree *tree, int val) {
  check_tree(tree);

  Node *node = malloc(sizeof(Node));
  if (!node) {
    fprintf(stderr, "Could not allocate memory for %d\n", val);
    exit(1);
  }

  node->value = val;

  if (!tree->root) {
    tree->root = node;
    return;
  }

  Node *curr = tree->root;

  while (true) {
    if (curr->value == val) {
      free(node); // If val already in tree, remove allocated node
      return;
    } else if (val < curr->value) {
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

void bt_remove(Tree *tree, int val) {
  check_tree(tree);

  Node *par = bt_get_parent(tree, val);

  if (!par)
    return;

  if (val < par->value) {
    free(par->left);
    par->left = NULL;
  } else {
    free(par->right);
    par->right = NULL;
  }
}

void bt_print(Tree *tree) {
  check_tree(tree);
  bt_print_helper(tree->root, 0);
}
