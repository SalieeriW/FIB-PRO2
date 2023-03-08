#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool &b)
{
    int dni = est.consultar_DNI();
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    if (vest[pos].consultar_DNI() != dni)
    {
        for (int i = nest; i > pos; i--)
        {
            vest[i] = vest[i - 1];
        }
        ++nest;
        vest[pos] = est;
        if (est.te_nota())
        {
            if (nest_amb_nota == 0)
                suma_notes = vest[pos].consultar_nota();
            else
                suma_notes += vest[pos].consultar_nota();
            ++nest_amb_nota;
        }
        b = false;
    }
    else
        b = true;
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool &b)
{
    b = false;
    int pos = cerca_dicot(vest, 0, nest - 1, dni);
    if (pos < nest and vest[pos].consultar_DNI() == dni)
    {
        if (vest[pos].te_nota())
        {
            --nest_amb_nota;
            suma_notes -= vest[pos].consultar_nota();
        }
        for (int i = pos; i < nest - 1; ++i)
        {
            vest[i] = vest[i + 1];
        }
        --nest;
        b = true;
    }
}