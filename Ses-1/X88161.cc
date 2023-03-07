#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct match
{
    int first, second;
};

typedef vector<match> entry_row;
typedef vector<int> answer_row;
typedef vector<answer_row> answer;
typedef vector<entry_row> entry;

void read_entry(entry &v, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j].first >> v[i][j].second;
        }
    }
}

void answer_init(answer &v, int n)
{
    for (int i = 0; i < n; ++i)
    {
        v[i][0] = i + 1;
    }
}

void answer_load(answer &a, const entry &e, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if (e[i][j].first > e[i][j].second)
                {
                    a[i][1] += 3;
                }
                else if (e[i][j].first == e[i][j].second)
                {
                    a[i][1] += 1;
                    a[j][1] += 1;
                }
                else
                {
                    a[j][1] += 3;
                }
                a[i][2] += e[i][j].first;
                a[j][2] += e[i][j].second;
                a[i][3] += e[i][j].second;
                a[j][3] += e[i][j].first;
            }
        }
    }
}

void answer_print(const answer &a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        bool primer = true;
        for (int j = 0; j < 4; ++j)
        {
            if (!primer)
                cout << " ";
            cout << a[i][j];
            primer = false;
        }
        cout << endl;
    }
}

bool cmp(const answer_row &a, const answer_row &b)
{
    if (a[1] != b[1])
        return a[1] > b[1];

    int a_diff = a[2] - a[3];
    int b_diff = b[2] - b[3];

    if (a_diff != b_diff)
        return a_diff > b_diff;

    return a[0] < b[0];
}

int main()
{
    int n;
    cin >> n;

    entry e(n, entry_row(n));
    answer a(n, answer_row(4, 0));

    read_entry(e, n);
    answer_init(a, n);
    answer_load(a, e, n);
    sort(a.begin(), a.end(), cmp);
    answer_print(a, n);
}