#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int zero = 0;
    int one = 0;
    int two = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            zero++;
        else if (arr[i] == 1)
            one++;
        else if (arr[i] == 2)
            two++;
    }

    int index = 0;

    for (int i = 0; i < zero; i++)
    {
        arr[index++] = 0;
    }

    for (int i = 0; i < one; i++)
    {
        arr[index++] = 1;
    }

    for (int i = 0; i < two; i++)
    {
        arr[index++] = 2;
    }

    cout << "Array after sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
