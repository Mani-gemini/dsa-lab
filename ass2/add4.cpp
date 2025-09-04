#include <iostream>
#include <vector>
using namespace std;
void sortarr(vector<int> &arr)
{
    int s = arr.size();
    int low = 0;
    int mid = 0;
    int high = s - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {0, 1, 2, 0, 1, 2};
    int s = arr.size();
    sortarr(arr);
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    return 0;
}
