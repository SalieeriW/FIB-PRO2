#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;


double redondear(double r)
{  
  return int(10.*(r + 0.05)) / 10.0;
} 

void process (Cjt_estudiants &entry) {
    string flag;
    cin >> flag;
    while (flag != "-6") {
        if (flag == "-1") {
            int dni;
            double nota;
            cin >> dni >> nota;
            if (entry.existeix_estudiant(dni)) {
                cout << "el estudiante " << dni << " ya estaba" << endl << endl;
            }
            else if (entry.mida() == entry.mida_maxima()) cout << "el conjunto esta lleno" << endl << endl;
            else {
                Estudiant temp (dni);
                if (nota >= 0 and nota <= 10) temp.afegir_nota(nota);
                entry.afegir_estudiant(temp);
            };
        }
        else if (flag == "-2") {
            int dni;
            cin >> dni;
            if (!entry.existeix_estudiant(dni)) {
                cout << "el estudiante " << dni << " no esta" << endl << endl;
            } 
            else if (!entry.consultar_estudiant(dni).te_nota()) {
                cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
            } 
            else {
                cout << "el estudiante " << dni << " tiene nota " << entry.consultar_estudiant(dni).consultar_nota() << endl << endl;
            }
        }
        else if (flag == "-3") {
            int dni;
            double nota;
            cin >> dni >> nota;

            if (!entry.existeix_estudiant(dni)) {
                cout << "el estudiante " << dni << " no esta" << endl << endl;
            } else {
                Estudiant temp = entry.consultar_estudiant(dni);
                if (temp.te_nota()) {
                    temp.modificar_nota(nota);
                }
                else {
                    temp.afegir_nota(nota);
                }
                entry.modificar_estudiant(temp);
            } 
        }
        else if (flag == "-4") {
            for (int i = 1; i <= entry.mida(); ++i) {
                Estudiant temp = entry.consultar_iessim(i);
                if (temp.te_nota()) {
                    double nota = temp.consultar_nota();
                    nota = redondear(nota);
                    temp.modificar_nota(nota);
                    entry.modificar_iessim(i, temp);
                }
            }
        }
        else if (flag == "-5") {
            entry.escriure();
            cout << endl;
        }
        cin >> flag;
    }
}

int main () {
    Cjt_estudiants entry;
    entry.llegir();
    process(entry);
}