//
// Created by Ronny Mandal on 04/10/2016.
//
#include <stdlib.h>
#include "avl_tree.h"

void insert_avl(struct t_node **t_node, int value) {
    if (*t_node == NULL) {
        *t_node = create_node(value);
        return;
    }

    if (value < (*t_node)->v) {
        insert_avl(&(*t_node)->left, value);
    } else {
        insert_avl(&(*t_node)->right, value);
    }
    /* Check balance of tree from current node. */

}

/* Return 0 if balanced, -1 if left over weight and 1 of right over weight. */
int check_balance(t_node *root) {


    return 0;
}
