//
// Created by Ronny Mandal on 29/09/2016.
//

#include "tree.h"

int mean(int* arr){
    int mean = 0;
    int length = sizeof(arr)/sizeof(int);
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++) {

        mean += arr[i];

    }
    return mean / length;
}