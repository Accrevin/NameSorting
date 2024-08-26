#include <iostream>
using namespace std;

void selectionSort(string arr[], int n)
//Sorts in decending order

{
    int i, a, min_idx;

    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (a = i + 1; a < n; a++) {
            if (arr[a] > arr[min_idx]) {
                min_idx = a;
            }
        }

        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

int binarySearch(string names[], string input, int n) {
    //Do the opposite from normal since its reversed
    int lower = 0;
    int upper = n - 1;

    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;

        if (input == names[mid]) {
            return mid;
        }

        if (input < names[mid]) { 
            lower = mid + 1;
        }

        else {
            upper = mid - 1;
        }
    }

    return -1;
}



int main() {
    //you can change this to whatever number of names you want
    string names[6];
    string ownName;

    for (int i = 0; i < 6; i++) {
        cout << "Please enter a name: ";
        cin >> names[i];
    }

    cout << "Unsorted List: ";
    for (int i = 0; i < 6; i++) {
        cout << names[i] << "\t";
    }
    cout << endl;
    selectionSort(names, 6);

    //sort here
    cout << "Sorted List: ";
    for (int i = 0; i < 6; i++) {
        cout << names[i] << "\t";
    }

    cout << endl;

    cout << "Please enter your own name: ";
    cin >> ownName;

    //search here
    int found = binarySearch(names, ownName, 6);
    if (found == -1) {
        cout << "Your name was not on the list";
    }
    else
        cout << "Your name was on the list";

}