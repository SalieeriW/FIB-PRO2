#include <iostream>
#include <vector>
#include <algorithm>
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


bool cmp (Estudiant &a, Estudiant &b) {
    double a_mark = a.consultar_nota();
    double b_mark = b.consultar_nota();
    if (a_mark != b_mark) return a_mark > b_mark;
    double a_dni = a.consultar_DNI();
    double b_dni = b.consultar_DNI();
    return a_dni < b_dni;
}
int main () {
    int m, n, s;
    cin >> m >> n >> s;
    vector <bool> selection (n, false);
    select(selection, s);
    vector <Estudiant> est (m);
    process(est, selection, s);
    sort(est.begin(), est.end(), cmp);
    for (int i = 0; i < m; ++i) {
        est[i].escriure();
    }

}