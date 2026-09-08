#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

int main(){

    int file = open("vectors-A.bin",O_RDONLY);
    if(file < 0){
        perror("Errore nell'apertura del file.\n");
        exit(EXIT_FAILURE);
    }

    struct stat infoFile;
    fstat(file,&infoFile);

    uint8_t *datiFile = mmap(NULL,infoFile.st_size,PROT_READ,MAP_PRIVATE,file,0);
    if(datiFile == MAP_FAILED){
        perror("Errore nella mappatura del file.\n");
        exit(EXIT_FAILURE);
    }

    for(size_t i = 0; i < infoFile.st_size; i++){
        printf("%d, ",datiFile[i]);
    }



}