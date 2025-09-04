#include <iostream>
using namespace std;
int main()
{
    cout <<"hello"<<endl;
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements of the array: "; 
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    int c=0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]==arr[j])
            {
                c++;
                break;
            } 
        }
    }
    cout<< "The number of distinct elements in the array is: " << size-c << endl;
    return 0;
}
