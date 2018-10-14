#include <iostream>
#include <cmath>

using namespace std;

bool perfect_square(int num)
{
    float temp = sqrt(num);

    if (temp - (int)sqrt(num) == 0)
        return true;

    else return false;
}

int main()
{
    cout << "Enter a number to test!: ";
    int num;
    cin >> num;
    
    if (perfect_square(num))
    {
        cout << num << " is a perfect square!";
    }
    else
    {
        cout << num << " is not a perfect square!";
    }
}

