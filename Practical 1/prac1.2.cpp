#include <iostream>
using namespace std;

int main()
{
    int ids[100];
    int n, i, j;
    int foundDuplicate = 0;

    cout << "Enter no of borrow records: ";
    cin >> n;

    cout << "Enter book ids:" << endl;
    for(i = 0; i < n; i++)
    {
        cin >> ids[i];
    }

    cout << "Duplicate ids are: ";

    for(i = 0; i < n; i++)
    {
        int count = 0;

        for(j = 0; j < i; j++)
        {
            if(ids[i] == ids[j])
                break;
        }

        if(j != i)
            continue;

        for(j = 0; j < n; j++)
        {
            if(ids[i] == ids[j])
                count++;
        }

        if(count > 1)
        {
            cout << ids[i] << " ";
            foundDuplicate = 1;
        }
    }

    if(foundDuplicate == 0)
    {
        cout << "No duplicate ids found";
    }

    cout << endl;

    return 0;
}
