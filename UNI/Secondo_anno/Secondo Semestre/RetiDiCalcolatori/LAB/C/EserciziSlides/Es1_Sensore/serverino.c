#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

//implementare anche TCP per il nodo di controllo

//serve un struct per salvare tutti i sensori
/*typedef struct{
    int count;


} SensorList;*/

int main(int argc, char *argv[]){

    if(argc != 4){
        fprintf(stderr,"Errore, devi avviarmi con <PORT-di-questo-sever> <IP-del_nodo_controllo> <PORT-del-nodo-controllo>\n");
        exit(EXIT_FAILURE);
    }

    int socketServerUDP;
    struct sockaddr_in infoUDP;

    memset(&infoUDP,0,sizeof(infoUDP));
    infoUDP.sin_family = AF_INET;
    infoUDP.sin_port = htons(atoi(argv[1]));
    infoUDP.sin_addr.s_addr = INADDR_ANY;

    if((socketServerUDP = socket(AF_INET,SOCK_DGRAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket UDP\n");
        exit(EXIT_FAILURE);
    }

    for(;;){

        //recvfrom(socketServerUDP,&ciao,0,NULL,NULL)

    }

}