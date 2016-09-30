#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(){

	/* Put some values in the tree. */
	int val[] = {41,3,6,5,76,4,6,2,8,98,67,3,54,34,52,7,23,10,54};

	/* Initialize the root. */
	t_node* root = initialize(val[0]);

	for(int i=1;i<(sizeof(val)/sizeof(int));i++) {
		insert(root, val[i]);
	}

	return 0;
}


t_node* initialize(int value) {
	t_node *root = create_node(value);

	return root;
}

t_node* create_node(int value) {
	t_node* node = malloc(sizeof(t_node));
	node->v = value;
    node->left = NULL;
	node->right = NULL;

	return node;
}

void insert(t_node *t_node, int value) {
	if( t_node == NULL ) {
		t_node = create_node(value);
		return;
	}

	if( value < t_node->v ) {
		insert(t_node->left, value);
		printf( "Inserted left\n" );
	}
	else {
		insert(t_node->right, value);
		printf( "Inserted right\n" );
	}
}
