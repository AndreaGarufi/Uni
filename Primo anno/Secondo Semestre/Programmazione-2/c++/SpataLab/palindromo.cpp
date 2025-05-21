#include <iostream>

using namespace std;

class Parola{
    public:
    Parola(string string):stringa(string){}

    bool isPalindroma(){

        this->stringa;
        for(int i = 0, j = stringa.length()-1; i < stringa.length() / 2; i++, j--){
            if(stringa[i] != stringa[j]){
                return false; 
            }
        }
        return true;
    }


    private:
    string stringa;
};

int main(){

    string parola;
    getline(cin,parola);

    Parola *a = new Parola(parola);
    cout << a->isPalindroma();

    return 0;
}