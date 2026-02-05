#include <iostream>
using namespace std;

// <-------------ESERCIZIO 1---------------->
int sommaDispariAGI(int n){
    if(n>0){
        return (2*n-1)+sommaDispari(n-1);
    }else{
        return 0;
    }
}

// <-------------ESERCIZIO 2---------------->
int cifreGARU(int n,int i){
    
    if((n/10)<1){
        return 1;
    }else{
        return i+cifre(n/10,i);
    }
}

float cifreAGI(float n){
    if(n>=1) return 1+cifreAGI(n/10);
    else return 0;
}

// <-------------ESERCIZIO 3---------------->
int sommaCifreAGI(int n){
    if(n>=1) return n%10 + sommaCifre(n/10);
    else return 0;
}

// <-------------ESERCIZIO 4---------------->
int mcdAGI(int a, int b){
    if(b == 0) return a;
    else return mcd(b, a%b);
}

// <-------------ESERCIZIO 5---------------->
int divisoreGARU(int n, int i, int k){
    if(k == 0){
        return 0;
    }else if(n%k == 0){
        return 1+divisore(n,i,k-1);
    }
    return divisore(n,i,k-1);
}

int divisoreAGI(int n, int k){
    if(k>0){
        if(n%k == 0) return 1+divisoreAGI(n, k-1);
        else return divisoreAGI(n, k-1);
    }
    return 0;
}

int main(){


    // cout << "Valore (sommaDispari): " << sommaDispari(10);;
    // cout << "CifreAGI (cifreAGI): " << cifreAGI(12312321) << endl;
    // cout << "sommaCifre (sommaCifre): " << sommaCifre(126) << endl;
    //cout << "mcd (mcd): " << mcd(12,32) << endl;
    // cout << divisoreAGI(10,10) <<endl;
    // cout << divisore(10,0,10) <<endl;
    // cout << cifre(178,1);

}
