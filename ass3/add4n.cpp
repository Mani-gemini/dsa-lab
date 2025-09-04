/*Given an array of integers temperatures represents the daily temperatures, return an
array answer such that answer[i] is the number of days you have to wait after the ith day to get a
warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead. */
#include <iostream>
#include <stack>
using namespace std;
int daysleft(int tempday, int temperatures[], int n, int index)
{
    int count = 0;
    for (int j = index + 1; j < n; j++)
    {
        count++;
        if (temperatures[j] > tempday)
        {
            return count;
        }
    }
    return 0;
}

int main()
{
    int temperatures[] = {23, 24, 25, 21, 19, 22, 26, 23};
    int n = sizeof(temperatures) / sizeof(temperatures[0]);

    cout << "Answer: ";
    int answer[n] = {0};
    for (int i = 0; i < n; i++)
    {
        answer[i] = daysleft(temperatures[i], temperatures, n, i);
        cout << answer[i] << " ";
    }
    return 0;
}
