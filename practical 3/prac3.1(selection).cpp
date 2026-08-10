#include <iostream>
using namespace std;

int main()
{
    int marks[100];
    int n, i, j, min, temp;

    cout << "Enter number of answer sheets: ";
    cin >> n;

    cout << "Enter marks:" << endl;
    for(i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(marks[j] < marks[min])
            {
                min = j;
            }
        }

        temp = marks[i];
        marks[i] = marks[min];
        marks[min] = temp;
    }

    cout << "\nSorted marks are:" << endl;
    for(i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}