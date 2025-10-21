#include <iostream>
using namespace std;

// <-------ESERCIZIO 1-------->
int arrayNegatiGARUFI(int* A,int i){
    if(i >= 0){
        if(A[i]<0){
            return 1 + arrayNegatiGARUFI(A,i-1);
        }else{
            return arrayNegatiGARUFI(A,i-1);
        }
    }else{
        return 0;
    }
}

int arrayNegatiGIRLANDO(int* A, int l){
    if(l>=0){
        if(A[l]<0) return 1+arrayNegatiGIRLANDO(A, l-1);
        else return 0+arrayNegatiGIRLANDO(A, l-1);
    }else return 0;
}

// <-------ESERCIZIO 2-------->

int ProdottoArray(int* A, int i){ 
    if(i>=0){
        if(A[i]%2 == 0) return A[i] * ProdottoArray(A, i-1);
        else return 1*ProdottoArray(A, i-1);
    }else return 1;
}

int ProdottoArrayGARUFI(int* A,int i, int k){
    if(i >= 0){
        if(A[i]%2 == 0){
            k = A[i];
            return k * ProdottoArrayGARUFI(A,i-1,k);
        }else{
            return ProdottoArrayGARUFI(A,i-1,k);
        }
    }else{
        return 1;
    }
}

// <-------ESERCIZIO 4-------->

int SommaArrayGARUFI(int* A,int i, int k){
    if(i >= 0){
        if(A[i]%2 == 0){
            k = A[i];
            return k + SommaArrayGARUFI(A,i-1,k);
        }else{
            k = A[i];
            return (-1*k) + SommaArrayGARUFI(A,i-1,k);
        }
    }else{
        return 0;
    }
}
SommaArrayGIRLANDO(int* A, int i, int SP, int SD){
    if(i>=0){
        if(A[i]%2==0) return SommaArrayGIRLANDO(A, i-1, SP+A[i], SD);
        else return SommaArrayGIRLANDO(A, i-1, SP, SD+A[i]); 
    }return SP-SD;
}


// <-------ESERCIZIO 5-------->

bool SimmGirlando(int* A, int i, int n){
    if(n-1-i>=0 && i>1){
        if(A[i] == A[n-1-i]) return true && SimmGirlando(A, i-1, n);
        else return false && SimmGirlando(A, i-1, n);
    } return true;
}

bool SimmGARUFI(int* A, int i, int n,int k){

    if(i >= 0){
        if(A[i] == A[n-1-i]){
            k++;
            return SimmGARUFI(A,i-1,n,k);
        }else{
            return SimmGARUFI(A,i-1,n,k);
        }
    }else if(k == n){
        return true;
    }else{
        return false;
    }

}

// <-------ESERCIZIO 6-------->

int PiccoGARUFI(int* A, int i){

    if(i > 0){
        if(A[i] > A[i-1] && A[i] > A[i + 1]){ 
            // cout << "SI" << A[i] <<endl;  
            return 1 + PiccoGARUFI(A,i-1);
        }else{
            return 0 + PiccoGARUFI(A,i-1);
        }
    }else{
        return 0;
    }

}

PiccoGirlando(int* A, int i){
    if(i>0){
        if(A[i]>A[i-1] && A[i]>A[i+1]) return 1 + PiccoGirlando(A, i-1);
        else return 0+PiccoGirlando(A, i-1);
    }else return 0;
}

int main(){

    int array[8] = {1,5,4,7,4,2,9,0};
    int arraySimm[5] = {10,3,1,3,10};
    // cout << "GARUFI " <<arrayNegatiGARUFI(array,4) <<endl;
    // cout << "GIRLANDO " << arrayNegatiGIRLANDO(array,4) <<endl;

    // cout << "GARUFI " << ProdottoArrayGARUFI(array,4,1) << endl;
    // cout << "GIRLANDO " << ProdottoArray(array,4) << endl;

    // cout << "GARUFI " << SommaArrayGARUFI(array,4,0) << endl;
    // cout << "GIRLANDO " << SommaArrayGIRLANDO(array,4,0,0) << endl;
    
    // cout << "GIRLANDO " << SimmGirlando(array,4,5) << endl;
    // cout << "GIRLANDO " << SimmGirlando(arraySimm,4,5) << endl;

    // cout << "GARUFI " << SimmGARUFI(array,4,5,0) << endl;
    // cout << "GARUFI " << SimmGARUFI(arraySimm,4,5,0) << endl;

    cout << "GARUFI " << PiccoGARUFI(array,6) << endl;
    cout << "GIRLANDO " << PiccoGirlando(array,6) << endl;

}