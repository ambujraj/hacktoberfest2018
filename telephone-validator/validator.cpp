#include<bits/stdc++.h>

using namespace std;
int main()
{
    string number;
    cout<<"Enter Mobile Number: ";
    cin>>number;

    bool flag = 0;
    int i = 0;
    while(number[i])
    {
        if(number[i] < 48 || number[i] > 57) //check if all the characters are numeric if not we set flag = 1
            {
                flag = 1;
                break;
            }
        i++;
    }

    if(!flag && number.length() == 10) //check if flag is not set and length is 10.
        cout<<"Phone Number Valid";
    else
        cout<<"Phone Number NOT Valid";

    return 0;
}
