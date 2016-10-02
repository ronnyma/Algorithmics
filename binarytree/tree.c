#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


t_node *initialize(int value) {
    t_node *root = create_node(value);

    return root;
}

t_node *create_node(int value) {
    t_node *node = (struct t_node *) malloc(sizeof(t_node));
    node->v = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void destroy(t_node *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}

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

void traverse(t_node *root) {
    if (root == NULL)
        return;

    traverse(root->left);
    printf("V: %i\n", root->v);
    traverse(root->right);
}
