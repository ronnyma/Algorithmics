#ifndef BINARYTREE_AVL_TREE_H
#define BINARYTREE_AVL_TREE_H

#include "tree.h"

void insert_avl(node_t **, int);

int check_balanced(node_t *);

void rebalance(node_t **t_node);

void inspect(node_t *);

void delete(node_t **, int);

void remove_node(node_t **);

void rotate_left(node_t **);

void rotate_right(node_t **);

void half_rotate_left(node_t **);

void half_rotate_right(node_t **);

int get_balance_factor(node_t *);

#endif //BINARYTREE_AVL_TREE_H
