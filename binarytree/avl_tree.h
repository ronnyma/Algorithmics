#ifndef BINARYTREE_AVL_TREE_H
#define BINARYTREE_AVL_TREE_H

#include "tree.h"

void insert_avl(t_node **, int);

int check_balanced(t_node *);

void rebalance(t_node **t_node);

void inspect(t_node *);

void rotate_left(t_node **);

void rotate_right(t_node **);

void half_rotate_left(struct t_node **);

void half_rotate_right(struct t_node **);

int get_balance_factor(t_node *);

#endif //BINARYTREE_AVL_TREE_H
