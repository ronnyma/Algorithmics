#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

//typedef struct node_t node_t;
typedef struct node_t {
    int balance_factor;
    int v;
    struct node_t *left;
    struct node_t *right;
} node_t;


node_t *initialize(int);

/* Return a node containing the value of the integer argument. */
node_t *create_node(int);

void dummy(int);

void traverse_infix(node_t *);

void traverse_postfix(node_t *);

void destroy(node_t *);

void visualize(node_t *);

int get_height(node_t *);

int search(node_t *, int);

void print_header();

void print_footer();

#endif //BINARYTREE_TREE_H
