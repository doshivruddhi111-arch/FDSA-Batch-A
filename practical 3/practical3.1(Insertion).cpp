#include <iostream>
using namespace std;

int main()
{
    int marks[100];
    int n, i, key, j;

    cout << "Enter number of answer sheets: ";
    cin >> n;

    cout << "Enter marks:" << endl;
    for(i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    for(i = 1; i < n; i++)
    {
        key = marks[i];
        j = i - 1;

        while(j >= 0 && marks[j] > key)
        {
            marks[j + 1] = marks[j];
            j--;
        }

        marks[j + 1] = key;
    }

    cout << "\nSorted marks are:" << endl;
    for(i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}