#include <iostream>
using namespace std;

int main()
{
    int marks[100];
    int n, i, j, temp;

    cout << "Enter number of answer sheets: ";
    cin >> n;

    cout << "Enter marks:" << endl;
    for(i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(marks[j] > marks[j + 1])
            {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted marks are:" << endl;
    for(i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}