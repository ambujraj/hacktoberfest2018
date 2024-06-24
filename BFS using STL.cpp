// BFS implementaion in stl c++
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int> arr[],int a,int b)
{
    arr[a].push_back(b);
    arr[b].push_back(a);
    
}
void explore(vector<int> arr[],vector<bool> &visited,int i)
{
    visited[i]=true;
    cout<<i<<" ";
    for(int k=0;k<arr[i].size();k++)
    {
        if(visited[arr[i][k]]==false)
        {
            cout<<arr[i][k]<<" ";
            visited[arr[i][k]]=true;
        }
    }
}
void BFS(vector<int> arr[],int n)
{
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            explore(arr,visited,i);
        }
    }
}
int main()
{
    int n;int e;
    cin>>n;
    cin>>e;
    int a,b;
    vector<int> arr[n];
    for(int i=0;i<e;i++)
    {
        cin>>a;
        cin>>b;
        addEdge(arr,a,b);
    }
    BFS(arr,n);
    
    
    return 0;
}
