#ifndef TREE_H
#define TREE_H


//struct _t_node;


typedef struct _t_node t_node;

typedef struct _t_node {
    int v;
    t_node *left;
    t_node *right;
};



t_node *initialize(int);

/* Inserts a node into the tree. t_node is the parent node, usually the root. */
void insert(t_node *, int);

/* Return a node containing the value of the integer argument. */
t_node *create_node(int);


#endif
