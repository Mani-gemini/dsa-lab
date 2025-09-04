#include <iostream>
using namespace std;
void remdup(int *arr,int size){
    
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]==arr[j])
            {
                for (int k = j; k < size; k++)
                {
                    arr[k]=arr[k+1];
                }
                size--;
            }
            
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<"     ";
    }
    
    
}
int main()
{
    cout <<"hello"<<endl;
    int arr[]={5,8,4,6,8,5,4,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    remdup(arr,size);
    return 0;
}
