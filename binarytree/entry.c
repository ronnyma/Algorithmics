
#include "entry.h"

int main() {

    /* Put some values in the tree. */
    int val[] = {41, 3, 6, 5, 76, 4, 6, 2, 8, 98, 67, 3, 54, 34, 52, 7, 23, 10, 54};

    /* Initialize the root. */
    t_node *root = initialize(val[0]);

    for (int i = 1; i < (sizeof(val) / sizeof(int)); i++) {
        insert(root, val[i]);
    }

    return 0;
}

