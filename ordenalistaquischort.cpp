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

    cout << "Lista aleatoria antes de ordenar:" << endl;
    for (int i = 0; i < n; i++) {
        int randomNum = rand() % 100; 
        lista.push_back(randomNum);
        cout << randomNum << " ";
    }
    cout << endl;

    quicksort(lista, lista.begin(), prev(lista.end()));

    cout << "Lista ordenada:" << endl;
    for (const int& num : lista) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
