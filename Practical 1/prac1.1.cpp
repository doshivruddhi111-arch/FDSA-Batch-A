#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, h, k, i;
    string items[100];

    cout << "Enter no of items: ";
    cin >> n;

    cout << "Enter item names:" << endl;

    for(i = 0; i < n; i++)
    {
        cin >> items[i];
    }

    cout << "Enter no of hours: ";
    cin >> h;

    k = h % n;

    cout << "Final display order:" << endl;

    for(i = k; i < n; i++)
    {
        cout << items[i] << " ";
    }

    for(i = 0; i < k; i++)
    {
        cout << items[i] << " ";
    }

    cout << endl;

    return 0;
}
