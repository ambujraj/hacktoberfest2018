#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, key, pos = -1;

    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];

    cout<<"Enter the Elements"<<endl;
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<endl<<"Enter the Key to Search: ";
    cin>>key;
    
    for(int i=0;i<n;i++)
    {
        if(key==a[i]){
            pos = i+1;
    		break;
        }

    }

    if(pos!=-1)
    {
        cout<<"Query is found at location: "<<pos<<endl;
    }
    else
    {
        cout<<"key not Found"<<endl;
    }

    return 0;
}
