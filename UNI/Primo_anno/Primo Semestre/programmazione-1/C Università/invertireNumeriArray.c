#include <stdio.h>

#define SIZE 4

int main() {
    int array[SIZE] = {7, 6, 5, 4};

    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    } 
}
