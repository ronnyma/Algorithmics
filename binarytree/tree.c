#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

	/* Initialize the root. */
	t_node* root = initialize();

	/* Put some values in the tree. */
	int val[] = {3,6,5,76,4,6,2,8,98,67,3,54,34,52,7,23,10,54};

	for(int i=0;i<(sizeof(val)/sizeof(int));i++) {
		insert_tree( root, val[i] );
	}

	return 0;
}

t_node* initialize() {
	t_node *root = create_node(32);

	return root;
}

t_node* create_node(int value) {
	t_node* node = malloc(sizeof(t_node));
	node->v = value;
    node->left = NULL;
	node->right = NULL;

	return node;
}

void insert_tree(t_node *t_node, int value) {
	if( t_node == NULL ) {
		t_node = create_node(value);
		return;
	}

	if( value < t_node->v ) {
		insert_tree( t_node->left, value );
		printf( "Inserted left\n" );
	}
	else {
		insert_tree( t_node->right, value );
		printf( "Inserted right\n" );
	}
}
