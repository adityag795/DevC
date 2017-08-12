#include<iostream>
#include<conio.h>
#include<functional>
#include<queue> 

using namespace std;

void display(priority_queue<int,vector<int>,greater<int>> gq)
{
    priority_queue <int,vector<int>,greater<int>> g = gq;
    while (!g.empty()) //empty() returns 0 if queue is not empty, otherwise it returns 1.
    {
        cout << g.top()<<"\t";
        g.pop();
    }
    cout << '\n';
}

int main() 
{ 
    priority_queue<int,vector<int>,greater<int>> minHeap;
    vector<int> arr = { 1, 2, 10, 8, 7, 3, 4, 6, 5, 9 };
    
    for (auto i : arr)
        minHeap.push(i);
    
    display(minHeap);
    
    return 0;
}    
