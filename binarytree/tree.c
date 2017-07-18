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
    node->balance_factor = 0;
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
        printf("\"%i(%i)\"->\"%i(%i)\";\n", root->v, root->balance_factor, root->left->v, root->left->balance_factor);
    } else {
        printf("null%i [shape=point];\n", null_count);
        printf("\"%i(%i)\"->\"null%i\" ;\n", root->v, root->balance_factor, null_count++);
    }
    if (root->right != NULL) {
        printf("\"%i(%i)\"->\"%i(%i)\";\n", root->v, root->balance_factor, root->right->v, root->right->balance_factor);
    } else {
        printf("null%i [shape=point];\n", null_count);
        printf("\"%i(%i)\"->\"null%i\" ;\n", root->v, root->balance_factor, null_count++);
    }

    visualize(root->left);
    visualize(root->right);
}

//TODO: use max(l,f) to get height.
int get_height(t_node *root) {
    if (root == NULL)
        return -1;
    int left = get_height(root->left);
    int right = get_height(root->right);

    if (right < left)
        return left + 1;
    else
        return right + 1;
}

void print_header() {

    printf("digraph G{\n\tgraph [ordering=\"out\"];\n");
}
void print_footer() {
    printf("}");
}

