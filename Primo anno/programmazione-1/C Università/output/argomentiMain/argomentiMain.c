#include <stdio.h>
#include <string.h>
int main(int argc, char **argv[]) {
    printf("Numero di argomenti: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n",i,argv[i]);
    }
   //printf("%s ",argv[0]);
}