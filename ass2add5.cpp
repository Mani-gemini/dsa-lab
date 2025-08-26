#include <bits/stdc++.h>
using namespace std;
// function to duplicate 2s in an array
void dup2(vector<int> &arr)
{
    int n = arr.size();
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 2)
        {
            arr.insert(arr.begin() + i, 2);
            i++;
            c++;
        }
    }
    for (int i = 0; i < c; i++)
    {
        arr.pop_back();
    }
}
int main()
{
    vector<int> arr = {1, 2, 0, 2, 4, 0};
    dup2(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
