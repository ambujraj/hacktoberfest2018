#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int num;
    cout << "Enter the number of element in UNSORTED array!! : ";
    cin >> num;
    int a[num];
    cout << "Enter the value in UNSORTED array" << endl;
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
        {
            cout << i + 1 << "st element: ";
        }
        else if (i == 1)
        {
            cout << i + 1 << "nd element: ";
        }
        else if (i == 2)
        {
            cout << i + 1 << "rd element: ";
        }
        else
        {
            cout << i + 1 << "th element: ";
        }
        cin >> a[i];
    }
    sort(a,a+num);
    cout << "The SORTED array is:" << endl;
    for (int i = 0; i < num; i++)
    {
        cout << a[i] << " ";
    }
}
