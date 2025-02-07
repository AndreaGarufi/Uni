#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *filePtr = NULL;

    if((filePtr = fopen("Registrazione.m4a","rb")) == NULL){
        printf("\nFile Non aperto\n");
    }else{
        printf("\nFile aperto\n");
    }
}