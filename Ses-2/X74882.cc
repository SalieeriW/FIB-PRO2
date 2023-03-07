#include <iostream>
#include "Estudiant.hh"
#include "Cjt_estudiants.hh"
using namespace std;

int main () {

    Cjt_estudiants list1, list2;
    list1.llegir();
    list2.llegir();

    int j = 1;
    while (j <= list1.mida()) {
        Estudiant a = list1.consultar_iessim(j);
        Estudiant b = list2.consultar_iessim(j);

        if (b.te_nota()){
            if (not a.te_nota() or (a.consultar_nota() < b.consultar_nota())){
                list1.modificar_iessim(j, b);
            }
        }
        ++j;
    }
    list1.escriure();
}
