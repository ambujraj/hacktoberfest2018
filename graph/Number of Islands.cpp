#include <bits/stdc++.h>
using namespace std;

bool isVisited[500][500] = {false}; //array to keep track of visited nodes
int n,m; //no. of rows and columns
int a[500][500]; //input matrix
int islandCount=0; //number of islands

void dfs(int x, int y){
    isVisited[x][y] = true;

    //utility arrays to make the traversing easy
    int posX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int posY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i=0; i<8; i++){
        int p = x+posX[i], q = y+posY[i];
        if(p>=0 && p<n && q>=0 && q<m){
            if(a[p][q] == 1 && !isVisited[p][q]){
                dfs(p,q);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<n; i++){
        getchar();
        for(int j=0; j<m; j++){
            a[i][j] = getchar()-48;
        }
    }

    //counting the number of islands
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 1 && !isVisited[i][j]){
                dfs(i,j);
                islandCount++;
            }
        }
    }
    cout<<islandCount;

    return 0;
}
