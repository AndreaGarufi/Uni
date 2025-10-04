// implementazione delle funzioni per la classe Pila 
using namespace std;

template <typename T> 
Pila<T>::Pila() : top(0)//vettore di inizializzazione (inizializzo la variabile top a 0 cosi ho l'array vuoto)
{
    dim = 5;
    array = new T[dim];
}

/*Pila<T>::Pila() 
{
    delete[] array;
}*/         //sistema il ditruttore

template <typename T>
void Pila<T>::Push(T elem)
{
    
    if(top < dim){
        array[top] = elem;
        cout << array[top] <<endl;
        top++;
        
    }else{
        dim = top *2;
        T *arrayDoppio = new T[dim];
        for(int i = 0; i < dim/2; i++){
            arrayDoppio[i] = array[i];
        }
        delete[] array;
        arrayDoppio[top] = elem;
        cout << arrayDoppio[top] <<endl;
        top++;
        array = arrayDoppio;
        
    }

        
}

template <typename T>
T Pila<T>::Pop()
{
    top--;
    return array[top];
}
