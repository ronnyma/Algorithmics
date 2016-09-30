#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


t_node *initialize(int value) {
    t_node *root = create_node(value);

    return root;
}

t_node *create_node(int value) {
    t_node *node = malloc(sizeof(t_node));
    node->v = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(t_node *t_node, int value) {
    if (t_node == NULL) {
        t_node = create_node(value);
        return;
    }

    if (value < t_node->v) {
        insert(t_node->left, value);
        printf("Inserted left\n");
    } else {
        insert(t_node->right, value);
        printf("Inserted right\n");
    }
}
