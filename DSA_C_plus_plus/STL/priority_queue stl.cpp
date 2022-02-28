#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;

    pq.push(23);
    pq.push(34);
    pq.push(21);
    pq.push(12);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    while(!pq.empty())
    {
        pq.pop();
    }
    cout<<pq.size();
    return 0;
}
