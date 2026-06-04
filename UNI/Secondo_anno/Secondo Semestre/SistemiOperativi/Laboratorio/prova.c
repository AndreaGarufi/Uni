#include <stdio.h> 
#include <stdint.h> 
#include <string.h> 
int main (){ 
    int x = 0x1234567; 
    uint8_t buffer[256]; //intero senza segno a 8bit quindi è = 1 byte oppure ad un char (il char è 1 byte)
    memcpy(buffer, &x, sizeof(x)); 
    for(int i = 0; i < sizeof(x); i++){ 
        printf("%02hhx ", buffer[i]); 
    } 
    printf("\n"); 
}