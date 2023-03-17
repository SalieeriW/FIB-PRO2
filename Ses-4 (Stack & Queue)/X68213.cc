#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void add(vector<stack<string>> &categories)
{
    string title;
    int cat_num;
    cin >> title >> cat_num;
    categories[cat_num - 1].push(title);
}
void remove(vector<stack<string>> &categories)
{
    int rm_num, cat_num;
    cin >> rm_num >> cat_num;
    for (int i = 0; i < rm_num; ++i)
    {
        categories[cat_num - 1].pop();
    }
}
void read(vector<stack<string>> categories)
{
    int cat_num;
    cin >> cat_num;
    cout << "Pila de la categoria " << cat_num << endl;
    for (int i = 0; not categories[cat_num - 1].empty(); ++i)
    {
        cout << categories[cat_num - 1].top() << endl;
        categories[cat_num - 1].pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<stack<string>> categories(n);

    int flag;
    cin >> flag;
    while (flag != -4)
    {
        if (flag == -1)
        {
            add(categories);
        }
        if (flag == -2)
        {
            remove(categories);
        }
        if (flag == -3)
        {
            read(categories);
        }
        cin >> flag;
    }
}