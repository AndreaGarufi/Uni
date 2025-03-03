#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePtr = NULL;
    int ret=1;
    if((filePtr = fopen("start.bat", "w")) == NULL){
        printf("Impossibile creare il file ");
    }else{
        printf("File creato\n");
        fprintf(filePtr,"START");
        fclose(filePtr);
    }

    system("start.bat");


}