#include <iostream>
using namespace std;
int main()
{
  int menu;
  int size;
  int arr[100];
  while(1){
      cout <<"enter the number to do taks "  <<endl<<"1.CREATE "<< endl <<"2.DISPLAY"<<endl;
      cout <<"3.INSERT"<<endl<<"4.DELETE"<<endl<<"5.LINEAR SEARCH"<<endl<<"6.EXIT"<<endl;
      cin>>menu;
      int size;
    if (menu==1){
                                                             ;
        cout<<"enter the size of arr"<<endl;
        cin>>size;
        for (int i = 0; i < size; i++) {
            cin>>arr[i];
        }
    }
    else if(menu==2){
        for (int i = 0; i < size; i++) {
            cout<<arr[i] ;
        }
        cout << endl;
    }
    else if(menu==3){
        int index;
        cout<<"enter index"<<endl;
        cin >> index;
        int element;
        cout<<"enter element ";
        cin>>element;
        cout<<endl;
        for (int i = size; i >=index; i--) {
            arr[i]=arr[i-1];
        }
        arr[index]=element;
        size++;
    }
    else if (menu==4){
        int index;
        cout<<"enter index"<<endl;
        cin >> index;
        for (int i = index; i < size; i++) {
            arr[i]=arr[i+1];
        }
        size--;
    }
    else if(menu==5){
        int element;
        cout<<"enter element ";
        cin>>element;
        cout<<endl;
        for (int i = 0; i < size; i++) {
            if (arr[i]==element){
                cout<<"element found at index : "<< i<<endl;
                break;
            }
        }
    }
    if (menu==6){
       break; 
    }
  }
    return 0;
}
