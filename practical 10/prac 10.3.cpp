#include <iostream>
using namespace std;

int main() {
    int table[10], n, id;

    for(int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student IDs:\n";

    for(int i = 0; i < n; i++) {
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        bool inserted = false;

        for(int j = 0; j < 10; j++) {
            int index = (h1 + j * h2) % 10;

            if(table[index] == -1) {
                table[index] = id;
                inserted = true;
                break;
            }
        }

        if(!inserted)
            cout << "Hash table is full!\n";
    }

    cout << "\nFinal Storage Table:\n";

    for(int i = 0; i < 10; i++)
        cout << "Slot " << i << ": " << table[i] << endl;

    return 0;
}