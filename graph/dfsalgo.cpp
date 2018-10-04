#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > v(100);
int visited[100], n;

void dfs(int x)
{
    visited[x]=1;
    //cout<<x<<" ";
    int i;
    for(i = 0;i<v[x].size();i++)
    {
       int temp = v[x][i];
       if(visited[temp] == 0)
       {
           dfs(temp);
       }
    }
}

int main()
{
    int e,a,b,i;
    cin>>n>>e;

    for(i=0;i<100;i++)
    {
        visited[i]=0;
        v[i].clear();
    }

    for(i=0;i<e;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(i=1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            dfs(i);
        }
    }

    return 0;
}
