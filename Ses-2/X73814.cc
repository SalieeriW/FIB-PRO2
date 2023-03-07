#include <vector>
#include <iostream>
#include "Estudiant.hh"
using namespace std;

void readstds(vector<Estudiant> &v)
{
    int n = v.size();
    for (int i = 0; i < n; ++i)
    {
        v[i].llegir();
    }
}

void printstds(const vector<Estudiant> &v, int j)
{
    for (int i = 0; i < j; ++i)
    {
        v[i].escriure();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<Estudiant> est(n);
    readstds(est);

    vector<Estudiant> ans(n);
    int j = 0;
    bool primer = true;
    for (int i = 0; i < n; ++i)
    {
        if (primer or (est[i].consultar_DNI() != est[i - 1].consultar_DNI()))
        {
            Estudiant temp(est[i].consultar_DNI());
            if (est[i].te_nota()) {
            temp.afegir_nota(est[i].consultar_nota());
            }
            ans[j] = temp;
            ++j;
        }
        else
        {
            if (est[i].te_nota() and (!est[i - 1].te_nota() or (est[i].consultar_nota() > est[i - 1].consultar_nota())))
            {
                if (ans[j - 1].te_nota()) {
                    ans[j - 1].modificar_nota(est[i].consultar_nota());
                }
                else {
                    ans[j - 1].afegir_nota(est[i].consultar_nota());
                }
            }
        }
        primer = false;
    }
    printstds(ans, j);
}