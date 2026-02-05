#include <iostream>
using namespace std;

class Heap{

    public:
    Heap():array{0,1,19,4,6,8,10,11,13,20},dim(10){}

    int* buildMax_heap(int *array, int dim);
    int* buildMin_heap(int *array, int dim);
    void max_heapfy(int *array, int i,int dim);
    void min_heapfy(int *array, int i,int dim);

    int* heapSort(int *array, int dim);
    void extractMax(int *array,int dim);
    
    void display();

    private:
    int array[10];
    int dim;

};

void Heap:: min_heapfy(int *array, int i,int dim){

    int left = (2*i)+1;
    int right = (2*i)+2;

    int min = i;
    if(left < dim && array[left] < array[min]){
        min = left;
    }
    if(right < dim && array[right] < array[min]){
        min = right;
    }

    if(min != i){
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        min_heapfy(array,min,dim);
    }

}


void Heap:: max_heapfy(int *array, int i,int dim){

    int left = (2*i)+1;
    int right = (2*i)+2;

    int max = i;
    if(left < dim && array[left] > array[max]){
        max = left;
    }
    if(right < dim && array[right] > array[max]){
        max = right;
    }

    if(max != i){
        int temp = array[i];
        array[i] = array[max];
        array[max] = temp;
        max_heapfy(array,max,dim);
    }

}

int* Heap:: buildMax_heap(int *array,int dim){

    for(int i = dim/2-1; i >= 0; i--){
        max_heapfy(array,i,dim);
    }

    return array;
}

int* Heap:: buildMin_heap(int *array,int dim){

    for(int i = dim/2-1; i >= 0; i--){
        min_heapfy(array,i,dim);
    }

    return array;
}

void Heap::extractMax(int *array,int n){
    int temp = array[n];
    array[n] = array[0];
    array[0] = temp;
    max_heapfy(array,0,n);
    
}

int* Heap:: heapSort(int *array, int dim){
    int n = dim;
    buildMax_heap(array,dim);
    for(int i = dim-1; i > 0; i--){
        n--;
        extractMax(array,n);
    }
    return array;
}

void Heap::display(){
    cout << "MAX-HEAP" <<endl;
    buildMax_heap(array,dim);

    for(int i = 0; i < dim; i++){
        cout << "|" << array[i];
    }
    cout << "|" <<endl;

    cout <<endl;
    
    cout << "MIN-HEAP" <<endl;
    buildMin_heap(array,dim);

    for(int i = 0; i < dim; i++){
        cout << "|" << array[i];
    }
    cout << "|" <<endl;

    cout <<endl;
    cout << "HEAP-SORT PARTENDO DA MAX HEAP" <<endl;
    heapSort(array,dim);
    for(int i = 0; i < dim; i++){
        cout << "|" << array[i];
    }
    cout << "|" <<endl;
}

int main(){
    Heap maxHeap;
    maxHeap.display();

}
