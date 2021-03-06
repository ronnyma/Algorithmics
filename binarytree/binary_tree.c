#include <stdio.h>
#include <stdlib.h>
#include "include/binary_tree.h"


void insert(node_t **t_node, int value) {
    if (*t_node == NULL) {
        *t_node = create_node(value);
        return;
    }

    if (value < (*t_node)->v) {
        insert(&(*t_node)->left, value);
    } else {
        insert(&(*t_node)->right, value);
    }
}


