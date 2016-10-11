#include <stdio.h>
#include <stdlib.h>
#include "entry.h"

int main() {

    //int val[] = {5, 4, 7, 23, 61, 9, 53, 2, 45, 71, 22, 82, 87, 15, 1, 16, 21, 93, 29};
    int val[] = {7,5,2,6};
    /* Initialize the root. */
    struct t_node *root = initialize(val[0]);

    for (int i = 1; i < sizeof(val) / sizeof(int); i++) {
        insert_avl(&root, val[i]);
    }


    //inspect(root);

    visualize(root);
    rotate_right(&root);
    printf("------\n");
    visualize(root);
    destroy(root);

    return 0;
}

