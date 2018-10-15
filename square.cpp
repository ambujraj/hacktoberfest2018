#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int a[9],b[8][9]= {{8,1,6,3,5,7,4,9,2},{6,1,8,7,5,3,2,9,4},{4,9,2,3,5,7,8,1,6},{2,9,4,7,5,3,6,1,8},{8,3,4,1,5,9,6,7,2},{4,3,8,9,5,1,2,7,6},{6,7,2,1,5,9,8,3,4},{2,7,6,9,5,1,4,3,8}};
    int min=1000,i,j;

    for(i=0;i<9;i++)
        cin>>a[i];
    for(i=0;i<8;i++)
    {
        int c=0;
        for(j=0;j<9;j++)
        {
            c+=abs(a[j]-b[i][j]);
            
        }
        if(min>c)
            min=c;
    }
    cout<<min<<endl;
    return 0;
}
