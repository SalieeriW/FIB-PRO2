#include <vector>
using namespace std;

struct parint {int prim, seg;};

parint max_min1(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
   el segundo componente del resultado es el valor minimo de v */
{
    parint ans;
    ans.prim = v[0];
    ans.seg = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > ans.prim) ans.prim = v[i];
        if (v[i] < ans.seg) ans.seg = v[i];
    }
    return ans;
}

pair<int,int> max_min2(const vector<int>& v)
/* Pre: v.size()>0 */
/* Post: el primer componente del resultado es el valor maximo de v;
el segundo componente del resultado es el valor minimo de v */
{
    pair<int,int> ans;
    ans.first = v[0];
    ans.second = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > ans.first) ans.first = v[i];
        if (v[i] < ans.second) ans.second = v[i];
    }
    return ans;
}

void max_min3(const vector<int>& v, int& x, int& y)
/* Pre: v.size()>0 */
/* Post: x es el valor maximo de v;  y es el valor minimo de v */
{
    x = v[0];
    y = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] > x) x = v[i];
        if (v[i] < y) y = v[i];
    }
}