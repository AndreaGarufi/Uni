//hello world

#include <iostream>
using namespace std;

int f(int x){
    return x*x;
}

int main(){
    int i = f(5);
    //std::cout <<"hello word" << i <<std::endl;        //cout è un costrutto del namespace standard "std" ma con using namespace std; posso evitare questa sintassi
    cout<<"hello word " << i <<endl;
    return 0;
}