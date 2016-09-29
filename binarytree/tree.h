#ifndef TREE_HEADER
#define TREE_HEADER

typedef struct t_node t_node;

struct t_node {
	int v;
	t_node* left;
	t_node* right;
};


t_node* initialize();


void insert_tree(t_node*, int);


t_node* create_node(int);

int mean(int*);

#endif
