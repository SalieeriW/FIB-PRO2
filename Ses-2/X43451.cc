#include "Estudiant.hh"
#include <vector>



void redondear_e_a(Estudiant& est) {
    est.modificar_nota((int(10*(est.consultar_nota() + 0.05)))/10.0);
}

void arrodonir_vector(vector<Estudiant>& v)
    /* Pre: cert */
    /* Post: els estudiants de v amb nota passen a tenir la seva nota arrodonida
    a la decima mes propera */
    {
        int n = v.size();
        for (int i = 0; i < n ; ++i) {
        if (v[i].te_nota()) {
            redondear_e_a(v[i]);
        }
        }
    }