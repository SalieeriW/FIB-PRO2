#include <iostream>
using namespace std;

int main () {

    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        int num;
        cin >> num;
        while (num != x) {
            sum += num;
            cin >> num;
        }
        string s;
        getline(cin,s);
        cout << "La suma de la secuencia "<< i << " es " << sum << endl;
    }
}