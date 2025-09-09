/*Write a program interleave the first half of the queue with second half. 
Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9*/
#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int>& q){
    int s = q.size();
    queue<int> q1;
    queue<int> q2;
    for (int i = 0; i < s; i++)
    {
        if (i<s/2)
        {
            q1.push(q.front());
            q.pop();
        }
        else
        {
            q2.push(q.front());
            q.pop();
        }
    }
    while(!q1.empty()&&!q2.empty())
    {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
}
int main()
{
    queue<int> q;
    cout<<"enter number of elements to get input"<<endl;
    int n;
    cin>>n;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        q.push(ele);
    }
    interleave(q);
    for (int i = 0; i < n; i++)
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}

