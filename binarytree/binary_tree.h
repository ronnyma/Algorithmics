#ifndef BINARYTREE_H
#define BINARYTREE_H


//struct _t_node;


typedef struct t_node t_node;


t_node *initialize(int);

/* Inserts a value into the tree. t_node is the parent node, usually the root. */
void insert(t_node**, int);

/* Return a node containing the value of the integer argument. */
t_node *create_node(int);

void traverse(t_node *);

void destroy(t_node*);

int search(t_node *, int);
#endif
