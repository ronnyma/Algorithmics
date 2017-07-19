#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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
    //TODO: balance tree
    //TODO: find a way to determine balance factor
    /* Update balance factor of nodes in the insertion path. */

    (*&(*t_node)->balance_factor) = get_balance_factor(*t_node);
    /* Determine rotation to perform. */

    //If node is right heavy
    if ((*t_node)->balance_factor > 1) {
        //if right child is right heavy: rotate left
        if (((*t_node)->right) != NULL && ((*t_node)->right)->balance_factor > 0) {
            rotate_left(t_node);
            //if right child is left heavy: half rotate right, rotate left
        } else if (((*t_node)->right) != NULL && ((*t_node)->right)->balance_factor < 0) {
            half_rotate_right(t_node);//&(*t_node)->right);
            rotate_left(t_node);
        }
        //If node is left heavy
    } else if ((*t_node)->balance_factor < -1) {
        //if left child is left heavy: rotate right
        if (((*t_node)->left) != NULL && ((*t_node)->left)->balance_factor < 0) {
            rotate_right(t_node);
            //if left child is right heavy: half rotate left, rotate right
        } else if (((*t_node)->left) != NULL && ((*t_node)->left)->balance_factor > 0) {
            half_rotate_left(t_node);//&(*t_node)->left);
            rotate_right(t_node);
        }
    }
    else {}//Do nothing

}


void inspect(t_node *root) {
    if (root == NULL)
        return;

    printf("Node: %i, %i\n", root->v, check_balanced(root));
    inspect(root->left);
    inspect(root->right);
}

/* Return 0 if balanced, -1 if left over weight and 1 of right over weight. */
int check_balanced(t_node *root) {
    int left = get_height(root->left);
    int right = get_height(root->right);
    int diff = abs(-left + right) > 1 ? 1 : 0;

    if (diff)
        return left > right ? -1 : 1;
    else
        return 0;
}

int get_balance_factor(t_node *root) {
    int left = get_height(root->left);
    int right = get_height(root->right);
    int diff = -left + right;

    return diff;
}

void rotate_right(struct t_node **t_node) {
    struct t_node *r = *t_node;
    struct t_node *p = r->left;

    r->left = p->right;
    p->right = r;
    *t_node = p;
}

void rotate_left(struct t_node **t_node) {
    struct t_node *r = *t_node; //4
    struct t_node *p = r->right; //7

    r->right = p->left;
    p->left = r;
    *t_node = p;
}

void half_rotate_right(struct t_node **t_node) {
    struct t_node *r = *t_node;
    struct t_node *p = (*t_node)->right->left;

    p->right = r->right;
    r->right->left = NULL;
    r->right = p;
}

void half_rotate_left(struct t_node **t_node) {
    struct t_node *r = *t_node;
    struct t_node *p = (*t_node)->left->right;

    p->left = r->left;
    r->left->right = NULL;
    r->left = p;
}
