#include <stdlib.h>
#include <stdio.h>
#include "include/avl_tree.h"


void insert_avl(t_node **t_node, int value) {
    if (*t_node == NULL) {//TODO: handle case where value exists
        *t_node = create_node(value);

        return;
    }

    if (value < (*t_node)->v) {
        insert_avl(&(*t_node)->left, value);
    } else if (value > (*t_node)->v) {
        insert_avl(&(*t_node)->right, value);
    }
    /* Update balance factor of nodes in the insertion path. */
    rebalance(t_node);
}


void rebalance(t_node **t_node) {
    if(*t_node == NULL) return;

    /* Update balance factor. */
    (*&(*t_node)->balance_factor) = get_balance_factor(*t_node);

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
}

void delete(t_node **root, int value) {
    if (*root == NULL)
        return;

    if ((*root)->v > value)
        delete(&((*root)->left), value);
    else if ((*root)->v < value)
        delete(&((*root)->right), value);

    if ((*root)->v == value) {
        remove_node(root);
    }

    rebalance(root);
}

/* Removes node node** and makes proper adjustments.
   Uses in-place operations. */
void remove_node(t_node **node) {
    //Node has zero children
    if ((*node)->left == NULL && (*node)->right == NULL) {
        free(*node);
        *node = NULL;

        return;
    }
    //Node has one child
    //TODO: sett pointer to NULL if child is removed
    if (((*node)->left != NULL ? 1 : 0) ^ ((*node)->right != NULL ? 1 : 0)) {
        //Take the only child and replace node with it.

        t_node **tmp = (*node)->left == NULL ? &((*node)->right) : &((*node)->left);
        free(*node);
        *node = *tmp;

        return;
    }

    //Node has two children
    //if ((*node)->left != NULL && (*node)->right != NULL) { free(node); }

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
    struct t_node *p = (*t_node)->left;

    r->left = p->right;
    p->right = r;
    *t_node = p;
}

void rotate_left(struct t_node **t_node) {
    struct t_node *r = *t_node;
    struct t_node *p = (*t_node)->right;

    r->right = p->left;
    p->left = r;
    *t_node = p;
}

void half_rotate_right(struct t_node **t_node) {
    struct t_node *r = *t_node;
    struct t_node *p = (*t_node)->right->left;

    r->right->left = p->right;
    p->right = r->right;
    r->right = p;
}

void half_rotate_left(struct t_node **t_node) {
    struct t_node *r = *t_node;
    struct t_node *p = (*t_node)->left->right;

    r->left->right = p->left;
    p->left = r->left;
    r->left = p;
}

