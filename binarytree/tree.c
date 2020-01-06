//
// Created by Ronny Mandal on 05/10/2016.
//
#include <stdlib.h>
#include <stdio.h>
#include "include/tree.h"

int null_count = 0;

node_t *initialize(int value) {
    node_t *root = create_node(value);

    return root;
}

node_t *create_node(int value) {
    node_t *node = (node_t *) malloc(sizeof(node_t));
    node->balance_factor = 0;
    node->v = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void destroy(node_t *root) {
    if (root != NULL) {
        destroy(root->left);
        destroy(root->right);
        free(root);
    }
}

void traverse_infix(node_t *root) {
    if (root == NULL)
        return;

    traverse_infix(root->left);
    printf("V: %i\n", root->v);
    traverse_infix(root->right);
}

void traverse_postfix(node_t *root) {
    if (root == NULL)
        return;

    traverse_infix(root->left);
    traverse_infix(root->right);
    printf("V: %i\n", root->v);

}

void visualize(node_t *root) {
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
int get_height(node_t *root) {
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
    printf("}\n");
}

