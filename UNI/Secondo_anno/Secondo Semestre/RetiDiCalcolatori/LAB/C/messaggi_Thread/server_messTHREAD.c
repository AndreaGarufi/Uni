#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define BUFFER_MAX 160
#define MAX_CLIENTS 64

typedef struct{

    int socketClient;
    struct sockaddr_in indirizzoPorta;
    //possiamo mettere altre informazioni sul client
} client_info_t;

typedef struct{

    int count;
    client_info_t* list[MAX_CLIENTS];
    pthread_mutex_t mutex;
}clients_list_t;

clients_list_t clients = {.count = 0};


void broadcast_message(const char* messaggio, int socketCheHaInviato){
    pthread_mutex_lock(&clients.mutex);

    for(int i = 0; i < clients.count; i++){

        if(clients.list[i]->socketClient == socketCheHaInviato){
            continue;
        }
        send(clients.list[i]->socketClient,messaggio,strlen(messaggio),0);

    }

    pthread_mutex_unlock(&clients.mutex);    
}

void * gestione_client(void *arg){
    client_info_t *client = (client_info_t*)arg;
    int socketClient = client->socketClient;
    char buffer[BUFFER_MAX];
    char ipAddress[INET_ADDRSTRLEN];
    int port = ntohs(client->indirizzoPorta.sin_port);
    inet_ntop(AF_INET, &client->indirizzoPorta.sin_addr,ipAddress,INET_ADDRSTRLEN);

    printf("Si e' collegato il client: %s:%d\n",ipAddress,port);
    
    pthread_mutex_lock(&clients.mutex);
    clients.list[clients.count] = client;
    clients.count++;
    pthread_mutex_unlock(&clients.mutex);

    for(;;){

        int numBytes = recv(socketClient, buffer,BUFFER_MAX,0);
        if(numBytes < 0){

            printf("Errore in ricezione");
            continue;
        }

        if(numBytes == 0){
            printf("Il client %s:%d si e' disconnesso\n",ipAddress,port);
            break;
        }

        printf("Il client %s:%d ha inviato %s a tutti\n", ipAddress,port,buffer);
        broadcast_message(buffer,socketClient);

        memset(buffer, 0, BUFFER_MAX);
    }
    close(socketClient);

    pthread_mutex_lock(&clients.mutex);
    for(int i = 0; i < clients.count; i++){
        if(clients.list[i]->socketClient == socketClient){
        //ho trovato il client che si sta disconnettendo
        free(clients.list[i]);
        for(int j = i; j < clients.count-1; j++){
            clients.list[j] = clients.list[j+1];
        }
        clients.count--;
        break;
    }
    }
    pthread_mutex_unlock(&clients.mutex);

    return NULL;
}

//server <PORT>
int main(int argc, char* argv[]) { 
    if(argc <2){ //remember, argv[0] is the same program! 
        printf ("Devi avviarmi usando <Port> \n");
        exit(1); 
    }

    int socketServer;
    struct sockaddr_in ipPortaServer;
    pthread_mutex_init(&clients.mutex, NULL);
    socketServer = socket(AF_INET, SOCK_STREAM,0);

    ipPortaServer.sin_family = AF_INET;
    ipPortaServer.sin_port = htons(atoi(argv[1]));
    ipPortaServer.sin_addr.s_addr = INADDR_ANY;

    socketServer = socket(AF_INET, SOCK_STREAM, 0);
    if(bind(socketServer, (struct sockaddr*)&ipPortaServer, sizeof(ipPortaServer)) < 0){
        printf("Errore di bind porta gia utilizzata:\n");
        exit(1);
    }

    listen(socketServer, MAX_CLIENTS);

    printf("Server in ascolto sulla porta: %s\n",argv[1]);

    /////////////////////////////////////

    for(;;){

        client_info_t *client = malloc(sizeof(client_info_t));
        socklen_t addrlen = sizeof(client->indirizzoPorta);


        client->socketClient = accept(socketServer,(struct sockaddr*)&client->indirizzoPorta,&addrlen);

        pthread_t clientThread;
        pthread_create(&clientThread, NULL, gestione_client, (void*)client);

    }
    close(socketServer);


}