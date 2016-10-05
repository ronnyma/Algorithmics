#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


int null_count = 0;


void insert(struct t_node **t_node, int value) {
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


