#include "Estudiant.hh"
#include <vector>

pair<int, int> max_min_vest(const vector<Estudiant> &v)
/* Pre: v no conte repeticions de dni  */
/* Post: si existeix a v algun estudiant amb nota, la primera component del
   resultat es la posicio de l'estudiant de nota maxima de v i la segona
   component es la posicio de l'estudiant de nota minima de v (si hi ha
   empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
   hi ha cap estudiant amb nota, totes dues components valen -1 */
{
    pair<int, int> ans;
    ans.first = -1;
    ans.second = -1;

    double max_mark = 0;
    double min_mark = Estudiant::nota_maxima();
    int max_dni = 0;
    int min_dni = 0;

    int n = v.size();

    for (int i = 0; i < n; ++i)
    {
        if (v[i].te_nota())
        {
            double temp_mark = v[i].consultar_nota();
            int temp_dni = v[i].consultar_DNI();
            if (temp_mark < min_mark or (temp_mark == min_mark and min_dni > temp_dni))
            {
                min_mark = temp_mark;
                min_dni = temp_dni;
                ans.second = i;
            }
            if (temp_mark > max_mark or (temp_mark == max_mark and max_dni > temp_dni))
            {
                max_mark = temp_mark;
                max_dni = temp_dni;
                ans.first = i;
            }
        }
    }
    return ans;
}