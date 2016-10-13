#include <stdlib.h>
#include <stdio.h>
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
    int balance = check_balanced(*t_node);
    if((*t_node)->right == NULL) {
        printf("LEFT!\n");
    }

    /* Determine rotation to perform. */

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

void rotate_right(struct t_node **t_node) {
    struct t_node * r = *t_node;
    struct t_node * p = r->left;

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
    struct t_node *p = r->right->left;

    p->right = r->right;
    r->right->left = NULL;
    r->right = p;


}

void half_rotate_left(struct t_node **t_node) {
    struct t_node *r = *t_node;
    struct t_node *p = r->left->right;

    p->left = r->left;
    r->left->right = NULL;
    r->left = p;

}
