#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

typedef struct t_node t_node;
typedef struct t_node {
    int balance_factor;
    int v;
    struct t_node *left;
    struct t_node *right;
} t_node;


t_node *initialize(int);

/* Return a node containing the value of the integer argument. */
t_node *create_node(int);

void traverse(t_node *);

void destroy(t_node *);

void visualize(t_node *);

int get_height(t_node *);

int search(t_node *, int);

void print_header();

void print_footer();

#endif //BINARYTREE_TREE_H
