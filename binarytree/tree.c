//
// Created by Ronny Mandal on 05/10/2016.
//
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int null_count = 0;

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

void traverse(t_node *root) {
    if (root == NULL)
        return;

    traverse(root->left);
    printf("V: %i\n", root->v);
    traverse(root->right);
}

void visualize(t_node *root) {
    if (root == NULL)
        return;

    if (root->left != NULL) {
        printf("\"%i\"->\"%i\";\n", root->v, root->left->v);
    } else {
        printf("null%i [shape=point, style=invis];\n", null_count);
        printf("\"%i\"->\"null%i\" [style=invis];\n", root->v, null_count++);
    }
    if (root->right != NULL) {
        printf("\"%i\"->\"%i\";\n", root->v, root->right->v);
    } else {
        printf("null%i [shape=point, style=invis];\n", null_count);
        printf("\"%i\"->\"null%i\" [style=invis];\n", root->v, null_count++);
    }

    visualize(root->left);
    visualize(root->right);
}

int height(t_node *root) {
    if (root == NULL)
        return -1;
    int left = height(root->left);
    int right = height(root->right);

    if (right < left)
        return left + 1;
    else
        return right + 1;
}
