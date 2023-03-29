#include <iostream>
#include <list>
using namespace std;

void add_value(list<int> &l, int value, int &max, int &min)
{
    if (l.empty())
        max = min = value;
    else if (value > max)
        max = value;
    else if (value < min)
        min = value;
    l.insert(l.end(), value);
}

void update_max_min(list<int> &l, int &max, int &min)
{

    list<int>::iterator it = l.begin();
    max = min = *it;
    while (it != l.end())
    {
        if (*it > max)
            max = *it;
        else if (*it < min)
            min = *it;
        ++it;
    }
}

bool delete_value(list<int> &l, int value, int &max, int &min)
{
    bool found = false;
    if (not l.empty())
    {
        list<int>::iterator it = l.begin();
        while (not found and it != l.end())
        {
            if (*it == value)
            {
                it = l.erase(it);
                found = true;
            }
            else
            {
                ++it;
            }
        }
        if (found and not l.empty() and (value == max or value == min))
            update_max_min(l, max, min);
    }
    return found;
}

int main()
{
    list<int> nums;
    int flag, value;
    cin >> flag >> value;

    int max, min;
    max = min = value;
    int count, sum;
    count = sum = 0;

    while (flag != 0 and value != 0)
    {
        if (flag == -1)
        {
            add_value(nums, value, max, min);
            sum += value;
            ++count;
        }
        else if (flag == -2)
        {
            bool found = delete_value(nums, value, max, min);
            if (found)
            {
                sum -= value;
                --count;
            }
        }
        if (not nums.empty())
            cout << min << " " << max << " " << sum / double(count) << endl;
        else
            cout << 0 << endl;
        cin >> flag >> value;
    }
}