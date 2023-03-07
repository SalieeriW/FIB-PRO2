#include <iostream>
#include <vector>
#include "Estudiant.hh"

void select (vector <bool> &selected, int s) {
    for (int i = 0; i < s; ++i) {
        int m;
        cin >> m;
        selected[m-1] = true;
    }
}

void process (vector <Estudiant> &v, const vector <bool> &selected, int s) {
    int k = v.size();
    int b = selected.size();
    for (int i = 0; i < k; ++i) {
        int dni;
        cin >> dni;
        Estudiant temp (dni);
        v[i] = temp;
        double sum = 0;
        for (int j = 0; j < b; ++j) {
            double mark;
            cin >> mark;
            if (selected[j]) {
                sum += mark;
            }
        }
        sum /= s; 
        v[i].afegir_nota(sum);
    }
}

int main () {
    int m, n, s;
    cin >> m >> n >> s;
    vector <bool> selection (n, false);
    select(selection, s);
    vector <Estudiant> est (m);
    process(est, selection, s);
    for (int i = 0; i < m; ++i) {
        est[i].escriure();
    }

}