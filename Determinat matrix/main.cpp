#include <iostream>

using namespace std;

int main()
{

    int a[3][3];
    det=a[1][1];
    for(k=1;k<=m;k++)
    { l=k+1;
    for(i=l;i<=n;i++)
    { for(j=l;j<=n;j++)
    a[i][j] = ( a[k][k]*a[i][j]-a[k][j]*a[i][k] )/a[k][k]; }
    det=det*a[k+1][k+1];
    }
    cout << endl;
    cout << "DETERMINANT = " << det << endl;
    cout << "------------------------" << endl;
}
