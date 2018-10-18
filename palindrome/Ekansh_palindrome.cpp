#include<iostream>
#include<string>

using namespace std;

int main()
{
        string s;
        bool check;
        cin >> s;
        for(long long int i=0; i<s.size(); i++){
        //      cout << s[i] << " ";

                if(s[i] == s[s.size()-1-i]){
                        check =true;
                }

                else{
                        check =false;
                }

        }


        if(check == true){
                printf("Palindrome \n");
        }
        else{
                printf("Not a Palindrome \n");

        }
        return 0;
}

