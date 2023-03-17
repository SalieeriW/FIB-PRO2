#include <iostream>
#include "CuaIOParInt.hh"
using namespace std;

void processCue(queue<ParInt> &input, queue<ParInt> &queue1, queue<ParInt> &queue2)
{
    int time1 = 0;
    int time2 = 0;
    while (not input.empty())
    {
        ParInt temp = input.front();
        if (time1 <= time2)
        {
            queue1.push(temp);
            time1 += temp.segon();
        }
        else
        {
            queue2.push(temp);
            time2 += temp.segon();
        }
        input.pop();
    }
}

int main()
{
    queue<ParInt> input, queue1, queue2;
    llegirCuaParInt(input);
    processCue(input, queue1, queue2);
    escriureCuaParInt(queue1);
    cout << endl;
    escriureCuaParInt(queue2);
}