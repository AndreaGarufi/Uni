#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *ptr = NULL;

    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int data = 30;
    int arrayProva[10] = {0};
    char stringa[] = {"ciao mondo\0"};
    char stringaProva[] = {'\0'};

    if((ptr = fopen("array.txt","wb+")) == NULL){
        printf("Errore nel creare il file");
    }else{
        printf("File creato correttamente");
    }

    fwrite(&data,sizeof(int),1,ptr);
    rewind(ptr);
    fread(&data,sizeof(int),1,ptr);

    printf("\ndata -> %d\n",data);

    fwrite(stringa,sizeof(char),11,ptr);
    fseek(ptr,-11,SEEK_CUR);
    fread(stringaProva,sizeof(char),11,ptr);
    rewind(ptr);
    printf("\n%s\n",stringaProva);

    puts("");
    fseek(ptr,0,SEEK_END);
    fwrite(array,sizeof(int),10,ptr);
    fseek(ptr,-10 * sizeof(int),SEEK_CUR);
    fread(arrayProva,sizeof(int),10,ptr);

    for(int i = 0; i < 10; i++){
        printf("%d ",arrayProva[i]);
    }

    fclose(ptr);


}