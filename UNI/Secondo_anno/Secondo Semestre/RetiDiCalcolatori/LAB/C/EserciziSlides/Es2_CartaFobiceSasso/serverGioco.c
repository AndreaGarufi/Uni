#include <stdlib.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <stdbool.h>

#define MAX_CLIENTS 2


typedef struct {
    char bufferMail[64];
    char bufferPass[24];
    bool registrazione;
} Accesso;


typedef struct        //struct con tutti i dati del client (tolta la password)
{
    int socketClient;
    char email[64];
    char password[24];
    bool autenticato;       //impostato a false appena il client si connette, messo a 1 appena fa il login

} Client_info;

typedef struct           //struct con la lista dei client
{
    int count;
    Client_info *list[MAX_CLIENTS];
    pthread_mutex_t mutex;

} Client_list;

Client_list clients = {.count = 0};

void *gestioneAutenticazione(void *arg){

    Client_info *player = (Client_info*)arg;
    Client_list giocatori;
    Accesso datiRicevuti;

    int bytesRicevuti = recv(player->socketClient,&datiRicevuti,sizeof(Accesso),0);

    if(bytesRicevuti <= 0){
        fprintf(stderr,"Il client non manda dati, potrebbe essersi disconnesso.\n");
        //exit(EXIT_FAILURE);
    }
    
    if(datiRicevuti.registrazione == 0){
        //caso del login

    }else if(datiRicevuti.registrazione == 1){
        //caso della registrazione
        pthread_mutex_lock(&giocatori.mutex);
        for(int i = 0; i < clients.count; i++){
            //if(clients.list[i]->)
        }

        pthread_mutex_unlock(&giocatori.mutex);
    }


}



int main(int argc, char *argv[]){

    if(argc != 2){
        fprintf(stderr,"Errore: devi avviarmi inserendo <PORT-server>\n");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_init(&clients.mutex, NULL);

    int socketServer;
    struct sockaddr_in indirizzoServer;

    memset(&indirizzoServer,0,sizeof(indirizzoServer));
    indirizzoServer.sin_family = AF_INET;
    indirizzoServer.sin_port = htons(atoi(argv[1]));
    indirizzoServer.sin_addr.s_addr = INADDR_ANY;

    if((socketServer = socket(AF_INET,SOCK_STREAM,0)) < 0){
        fprintf(stderr,"Errore nella creazione della socket.\n");
        exit(EXIT_FAILURE);
    }

    if((bind(socketServer,(struct sockaddr*)&indirizzoServer,sizeof(indirizzoServer))) < 0){
        fprintf(stderr,"Errore nel bind della socket.\n");
        exit(EXIT_FAILURE);
    }

    listen(socketServer,MAX_CLIENTS);
    printf("Server in ascolto sulla porta %s.\n",argv[1]);

    for(;;){

        Client_info *player = malloc(sizeof(Client_info));
        player->socketClient = accept(socketServer,NULL,NULL);
        player->autenticato = 0;

        //creare thread che gestisce l'autencazione/registrazione con un limite di tentaviti, in caso di successo aggiungere il client in lista
        pthread_t threadAutenticazione;
        pthread_create(&threadAutenticazione,NULL,gestioneAutenticazione,(void*)player);

    }
}