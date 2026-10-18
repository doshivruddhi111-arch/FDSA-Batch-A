#include <iostream>
using namespace std;

int main() {
    int table[10], n, id;

    for(int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter registration numbers:\n";

    for(int i = 0; i < n; i++) {
        cin >> id;
        int index = id % 10;
        int start = index;

        while(table[index] != -1) {
            index = (index + 1) % 10;

            if(index == start) {
                cout << "Parking lot is full!\n";
                break;
            }
        }

        if(table[index] == -1)
            table[index] = id;
    }

    cout << "\nFinal Parking Slots:\n";
    for(int i = 0; i < 10; i++)
        cout << "Slot " << i << ": " << table[i] << endl;

    return 0;
}