#include <stdio.h>
#include <stdlib.h>
#include "entry.h"

int main() {

    /* Initialize the root. */
    struct t_node *root = initialize(50000);
    insert(&root, 50000);

    for (int i = 1; i < 100000; i++) {
        insert(&root, rand() % (100000 + 1) + 0);
    }


    traverse(root);

    destroy(root);

    return 0;
}

