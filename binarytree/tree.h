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


void insert(t_node *, int);


t_node *create_node(int);


#endif
