#include <stdio.h>
#include <stdlib.h>

int main(){

    int **matriceINT;

    char **matriceCHAR;

    matriceINT =(int**) malloc(sizeof(int)*4);

    for(int i = 0;i < 4; i++){
        matriceINT[i] = malloc(sizeof(int) * 5);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            matriceINT[i][j] = rand() % 50;
            printf(" %d ",matriceINT[i][j]);
        }
        puts("");
    }


    matriceCHAR = (char**) malloc(sizeof(char)*4);

    for(int i = 0; i < 4;i++){
        matriceCHAR[i] = malloc(sizeof(int)*5);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            
            int num = 65 + rand() % 90;
            char lettera = (char)num;
            matriceCHAR[i][j] = lettera;
            printf(" %c ",matriceCHAR[i][j]);
        }
        puts("");
    }   

}