#include "include/binary_tree.h"
#include "include/avl_tree.h"

int main() {
    int val[] = {5, 4, 7, 23, 9, 53, 2, 45, 71, 22, 82, 87, 15, 1, 16, 21, 93, 29, 120, 84, 10, 3, 44};
    int var[] = {15};

    /* Initialize the root. */
    struct t_node *root = initialize(val[0]);

    for (int i = 1; i < sizeof(val) / sizeof(int); i++) {
        insert_avl(&root, val[i]);
    }

    for (int i = 0; i < sizeof(var) / sizeof(int); i++) {
        delete(&root, var[i]);
    }

    print_header();
    visualize(root);
    print_footer();

    destroy(root);
    return 0;
}

