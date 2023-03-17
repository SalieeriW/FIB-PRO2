#include <iostream>
#include <stack>
using namespace std;


bool is_palindrome (stack <int> seq, int n) {
    for (int i = 0; i < n; ++i) {
        int num;
        if (i < n/2) {
            cin >> num;
            seq.push(num);
        }
        else if (n%2 == 1 and i == n/2) {
            cin >> num;
        } 
        else {
            cin >> num;
            if (num != seq.top()) return false;
            seq.pop();
        }
        } 
    return true;
}

int main () {
    int n;
    cin >> n;
    stack <int> seq;
    if (is_palindrome(seq, n)) cout << "SI" << endl;
    else cout << "NO" << endl;
}