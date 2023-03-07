
#include <iostream>
#include <vector>
using namespace std;

int busqueda_lin(const vector<int>& v, int x){
    
    int i = 0; 
    while (i < v.size()) {
        if (v[i] == x) return i;
        ++i;
    }
    return v.size();
}
 /* Pre: cierto */
 /* Post: si el resultado es v.size(), x no esta en v;
    en caso contrario, indica la posicion de la primera aparicion de x en v */
