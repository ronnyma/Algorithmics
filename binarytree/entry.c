#include <stdio.h>
#include <stdlib.h>
#include "entry.h"

int main() {

    int val[] = {5, 4, 7, 23, 61, 9, 53, 2, 45, 71, 22, 82, 87, 15, 1, 16, 21, 93, 29};
//    //int val[] = {7,5,2,6};
//
//
//
//    struct t_node *root = initialize(7);
//    root->left = create_node(9);
//    root->left->left = create_node(21);
//    root->right = create_node(9);
//
//    if (root->right == NULL)
//        printf("No right\n");
//    else {
//        printf("Right\n");
//        if (root->right->right == NULL)
//            printf("No right->right\n");
//        else
//            printf("Right->right found\n");
//
//        if (root->right->left == NULL)
//            printf("No right->left\n");
//        else
//            printf("Right->left found\n");
//    }
//
//    if (root->left == NULL)
//        printf("No left\n");
//    else {
//        printf("Left\n");
//        if (root->left->left == NULL)
//            printf("No left->left\n");
//        else
//            printf("Left->left found\n");
//         if (root->left->right == NULL)
//            printf("No left->right\n");
//        else
//            printf("Left->right found\n");
//    }
//


    /* Initialize the root. */
    struct t_node *root = initialize(val[0]);

    for (int i = 1; i < sizeof(val) / sizeof(int); i++) {
        insert_avl(&root, val[i]);
    }


    print_header();
    visualize(root);
    print_footer();

    destroy(root);

    return 0;
}

