// Exercise 5.9 Solution 

/*
(Costo del parcheggio) Un garage fa pagare una tariffa minima di $2,00 per parcheggiare
fino a tre ore, più $0,50 all’ora per ogni ora o parte di essa oltre le tre ore. Il costo massimo
per un dato periodo di 24 ore è di $10,00. Supponete che nessuna macchina resti parcheggiata
per più di 24 ore. Scrivete un programma che calcoli e stampi i costi del parcheggio per
ciascuno dei tre clienti che ieri hanno parcheggiato le loro auto in questo garage. Dovete
inserire le ore di parcheggio per ogni cliente. Il vostro programma deve stampare i risultati
in un formato tabellare e deve calcolare e stampare il totale degli incassi di ieri. Il programma
deve usare la funzione calculateCharges per determinare il costo per ogni cliente. Il
vostro output deve avere il seguente formato:

Car Hours Charge
1 1.5 2.00
2 4.0 2.50
3 24.0 10.00
TOTAL 29.5 14.50 
*/

#include <stdio.h>
#include <math.h>

double calculateCharges(double hours); // function prototype 

int main() { 
   printf("%s", "Enter the hours parked for 3 cars: ");
   int first = 1; // flag for printing table headers 
   double totalCharges = 0.0; // total charges for all cars 
   double totalHours = 0.0; // total number of hours for all cars 

   // loop 3 times for 3 cars 
   for (int i = 1; i <= 3; ++i) { 
      double h; // number of hours for current car 
      scanf("%lf", &h);
      totalHours += h; // add current hours to total hours 
   
      // if first time through loop, display headers 
      if (first) { 
         printf("%5s%15s%15s\n", "Car", "Hours", "Charge");

         // set flag to false to prevent from printing again 
         first = 0; 
      }  
   
      // calculate current car's charge and update total 
      double currentCharge; // parking charge for current car 
      totalCharges += (currentCharge = calculateCharges(h));

      // display row data for current car 
      printf("%5d%15.1f%15.2f\n", i, h, currentCharge);
   }  

   // display row data for totals 
   printf("%5s%15.1f%15.2f\n", "TOTAL", totalHours, totalCharges);
}  

// calculateCharges returns charge according to number of hours 
double calculateCharges(double hours) { 
   double charge; // calculated charge 

   // $2 for up to 3 hours 
   if (hours < 3.0) {
      charge = 2.00;
   }  

   // $.50 for each hour or part thereof in excess of 3 hours 
   else if (hours < 19.0) {
      charge = 2.00 + .50 * ceil(hours - 3.0);
   }  

   else { // maximum charge $10 
      charge = 10.0;
   }  
   
   return charge; // return calculated charge 
} 




 /*************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
