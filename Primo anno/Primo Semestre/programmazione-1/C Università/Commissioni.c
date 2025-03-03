/*(Commissioni sulle vendite) Usate un array unidimensionale per risolvere il seguente problema, 
Un’ azienda paga i suoi agenti di vendita su commissione.
Gli agenti di vendita ricevono $200 alla settimana più il 9% delle loro vendite lorde per quella settimana. 
Per esempio, un agente di vendita che ottiene un introito lordo sulle vendite di $3000 in una settimana riceve
$200 più il 9% di $3000, ovvero un totale di $470. Scrivete n programma in C {usando un array di contatori) 
che determini quanti agenti di vendita hanno avuto i loro guadagni in ognuno dei seguenti intervalli 
(supponete che il guadagno di ogni agente di vendita sia troncato a una quantità intera):
a) $200-299 b) $300-399 c) $400-499 d) £500-599 e) $600-699 f) $700-799 g) $800-899 h) $900-999 i} $1000 e oltre
PAG 261 libro, PDF pag 307*/ 

#include <stdio.h>
int main(){

int arrayF[9] = {0};

int salario = 0;

printf("Inserisci un salario per continuare o -1 per fermarti\n");
while(salario != -1){

printf("Inserisci il salario. \n");
scanf("%d",&salario);

if (salario > 999){
    arrayF[8]++;

    }else if (salario > 899){
    arrayF[7]++;

        }else if (salario > 799){
            arrayF[6]++;

            }else if (salario > 699){
                arrayF[5]++;
                
                }else if (salario > 599){
                    arrayF[4]++;

                    }else if (salario > 499){
                        arrayF[3]++;

                        }else if (salario > 399){
                            arrayF[2]++;

                            }else if (salario > 299){
                                arrayF[1]++;
                                
                                    }else if (salario != -1){
                                        arrayF[0]++;
                                        }

}
printf("Stampa delle fascie di salario: ");
printf("\n 200-299 %5d\n 300-399 %5d\n 400-499 %5d\n 500-599 %5d\n 600-699 %5d \n 700-799 %5d\n 800-899 %5d \n 900-999 %5d \n 1000+ %7d\n",arrayF[0],arrayF[1],arrayF[2],arrayF[3],arrayF[4],arrayF[5],arrayF[6],arrayF[7],arrayF[8]);


}
