#include <iostream>
#include <list>
#include <cstdlib> 
#include <ctime>   
using namespace std;

list<int>::iterator particion(list<int>& lista, list<int>::iterator rta, list<int>::iterator end) {
    int p = *end;
    list<int>::iterator pI = rta;

    for (list<int>::iterator i = rta; i != end; ++i) {
        if (*i <= p) {
            iter_swap(i, pI);
            ++pI;
        }
    }

    iter_swap(pI, end);
    return pI;
}

void quicksort(list<int>& lista, list<int>::iterator rta, list<int>::iterator end) {
    if (rta == end || distance(rta, end) == 1) {
        return;
    }

    list<int>::iterator p = rta;
    advance(p, distance(rta, end) - 1);
    list<int>::iterator pIndex = particion(lista, rta, p);
    quicksort(lista, rta, prev(pIndex));
    quicksort(lista, next(pIndex), end);
}

int main() {
    srand(time(0));

    int n = 10; 
    list<int> lista;
    int arbol[100];
    cout << "Lista aleatoria antes de ordenar:" << endl;
    for (int i = 0; i < n; i++) {
        int randomNum = rand() % 100; 
        arbol[i] = randomNum;
        cout << randomNum << " ";
    }
    cout << endl;
    
    cout << "arbolito xd" << endl;
    
    for(int i = 0; i< sizeof(arbol)/sizeof(arbol[0]); i++){
        if(i == 0){
            cout << "           " << arbol[i];
        }
        if(i >0 && i<3){
            cout << "       "<< arbol[i+1] << "       "<< arbol[i+2];
            i+= 2;
        }
        cout<<endl;
        if( i > 2 && i < 7){
            cout << "   "<<arbol[i+3]<< "   "<<arbol[i+4]<< "   "<<arbol[i+5]<< "   "<<arbol[i+6];
            i+=4;
        }
    }


    return 0;
}