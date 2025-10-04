#include <stdio.h>

#define SIZE 5

int main(){

int n[SIZE] = {19, 3, 15, 7, 11};

printf("%s%13s%17s\n", "Element", "Value", "Histogram");

for(int i = 0; i < SIZE; i++){          //qui scorre ogni elemento e lo stampa in forma tabellare

    printf("%7u%13d ", i, n[i]);

    for(int j=1;j < n[i]; j++){         //qui per ogni elemento stampa il valore in asterischi (es. n[i]=19 --> 19 asterischi)

        printf("%c", '*');
    }
    printf("\n");

}




}