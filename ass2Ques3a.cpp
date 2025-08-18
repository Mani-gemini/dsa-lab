#include <iostream>
using namespace std;
int main()
{
    cout << "hello" << endl;
    int n;
    cout << "Enter the size of the array (n): ";
    cin >> n;
    int arr[n];
    cout << "Enter distinct integers in the range of 1 to " << n + 1 << ": ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = ((n + 1) * n) / 2;
    int sumarr = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sumarr += arr[i];
    }
    int missingNumber = sum - sumarr;
    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}
