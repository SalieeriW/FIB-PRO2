#include <iostream>
#include <stack>
using namespace std;

bool closed (stack<char> &seq, int &count) {
    char c;
    cin >> c;
    while (c != '.') {
        ++count;
        if (c == '(' or c == '[') seq.push(c);
        else if (seq.empty()) return false;
        else if (c == ')' or c == ']') {
            if ((c == ')' and seq.top() != '(') or (c == ']' and seq.top() != '[')) return false;
            else seq.pop();
        } 
        cin >> c;
    }
    if (seq.empty()) return true;
    return false;
}

int main () {
    stack <char> seq;
    int count = 0;
    if (closed(seq, count)) cout << "Correcte" << endl;
    else cout << "Incorrecte " << count << endl;
}