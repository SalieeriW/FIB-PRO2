#include <iostream>
#include <queue>
using namespace std;

void refresh_max_min(queue<int> input, int &max, int &min)
{
    max = -1001;
    min = 1001;
    while (not input.empty())
    {
        int num = input.front();
        if (num < min)
            min = num;
        if (num > max)
            max = num;
        input.pop();
    }
}

void process_data()
{
    queue<int> input;

    double average = 0;
    int min = 1001;
    int max = -1002;
    int counter = 0;

    int num;
    cin >> num;

    while (num >= -1001 and num <= 1000)
    {
        if (num == -1001)
        {
            if (not input.empty())
            {
                int front = input.front();
                average -= front;
                input.pop();
                if (front == max or front == min)
                    refresh_max_min(input, max, min);
                --counter;
            }
        }
        else
        {
            input.push(num);
            if (num < min)
                min = num;
            if (num > max)
                max = num;
            average += num;
            ++counter;
        }
        if (not input.empty())
        {
            cout << "min " << min << "; max " << max << "; media " << average / input.size() << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        cin >> num;
    }
}

int main()
{
    process_data();
}