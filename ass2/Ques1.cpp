#include <iostream>
using namespace std;
int main() {
	int size;
	cout << "enter size of array" <<endl;
	cin>>size;
	int arr[size];
	int num,left,right;
	cout<<"enter the number to find"<<endl;
	cin>>num;
	left=0;
	right=size-1;
	int mid=(left+right)/2;
	cout<<"enter elements of array "<<endl;
	for (int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
	while(left<=right) {
		if(num==arr[mid]) {
			cout<<"index of number is "<< mid<<endl;
			break;
		}
		if(num>mid) {
			left=mid;
		}
		else {
			right=mid;
		}
	}
	return 0;
}
