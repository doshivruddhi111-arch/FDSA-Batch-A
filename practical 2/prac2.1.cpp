#include <iostream>
#include <vector>
#include <string>
using namespace std;


int searchPlate(vector<string>& plates, string target, int index) {
    if (index == plates.size()) {
        return -1;
    }


    if (plates[index] == target) {
        return index;
    }
    
    return searchPlate(plates, target, index + 1);
}

int main() {
    int n;

    cout << "Enter number of license plates: ";
    cin >> n;

    vector<string> plates(n);

    cout << "Enter license plates:\n";

    for (int i = 0; i < n; i++) {
        cin >> plates[i];
    }

    string target;

    cout << "Enter target license plate: ";
    cin >> target;

    int position = searchPlate(plates, target, 0);

    if (position != -1) {
        cout << "Target plate found at position: "
             << position + 1 << endl;
    } else {
        cout << "Target plate not found." << endl;
    }

    return 0;
}
