#include <iostream>
using namespace std;

const int myArray_size = 20;  // Use a constant for myArrayay size
int myArray[myArray_size] = {1, 4, 2, 8, 5, 9, 3, 7, 6, 0, 8, 5, 8, 4, 9, 19, 10, 7, 19, 34};
int numElements = 20;      // Track the number of elements

// Function prototypes
void displaymyArray();
void insertElement();
void deleteElement();
void swapElements();
void reversemyArray();
int findElement();

int main() {
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Display Contents\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Swap Elements\n";
        cout << "5. Reverse The Contents\n";
        cout << "6. Find Element\n";
        cout << "7. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaymyArray();
                break;
            case 2:
                insertElement();
                break;
            case 3:
                deleteElement();
                break;
            case 4:
                swapElements();
                break;
            case 5:
                reversemyArray();
                break;
            case 6:
                findElement();
                break;
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}

void displaymyArray() {
    cout << "myArray contents: ";
    for (int i = 0; i < numElements; i++) { 
        cout << myArray[i] << " ";
    }
    cout << endl;
}
void insertElement() {
    int pos, value;
    cout << "Enter position to insert (1-" << myArray_size << "): ";
    cin >> pos;
    if (pos < 1 || pos > myArray_size || numElements == myArray_size) {
        cout << "Invalid position or myArray is full!\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;

    for (int i = numElements - 1; i >= pos - 1; i--) {
        myArray[i + 1] = myArray[i];
    }
    myArray[pos - 1] = value;
    numElements++;
    cout << "Element inserted successfully!\n";
}

void deleteElement() {
    int pos;
    cout << "Enter position to delete (1-" << numElements << "): ";
    cin >> pos;
    if (pos < 1 || pos > numElements) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = pos - 1; i < numElements - 1; i++) {
        myArray[i] = myArray[i + 1];
    }
    numElements--;
    cout << "Element deleted successfully!\n";
}

void swapElements() {
    int pos1, pos2;
    cout << "Enter positions to swap (1-" << numElements << "): ";
    cin >> pos1 >> pos2;
    if (pos1 < 1 || pos1 > numElements || pos2 < 1 || pos2 > numElements) {
        cout << "Invalid positions!\n";
        return;
    }

    int temp = myArray[pos1 - 1];
    myArray[pos1 - 1] = myArray[pos2 - 1];
    myArray[pos2 - 1] = temp;
    cout << "Elements swapped successfully!\n";
}

void reversemyArray() {
    for (int i = 0; i < numElements / 2; i++) {
        int temp = myArray[i];
        myArray[i] = myArray[numElements - i - 1];
        myArray[numElements - i - 1] = temp;
    }
    cout << "myArray reversed successfully!\n";
}

int findElement() {
    int value, pos = -1;
    cout << "Enter value to find: ";
    cin >> value;

    for (int i = 0; i < numElements; i++) {
        if (myArray[i] == value) {
            pos = i + 1;
            break;
        }
    }

    if (pos != -1) {
        cout << "Element found at position " << pos << endl;
    } else {
        cout << "Element not found!\n";
    }
    return pos;
}