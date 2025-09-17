#include <iostream>
using namespace std;

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
     createArray(arr,n);
    if (n == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n) {
    createArray(arr,n);
    int pos, value;
    cout << "Enter position to insert ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value to insert: ";
    cin >> value;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
     for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << "Element inserted successfully.\n";
}

void deleteElement(int arr[], int &n) {
     createArray(arr,n);
    int pos;
    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << "Element deleted successfully.\n";
}

void linearSearch(int arr[], int n) {
     createArray(arr,n);
    int key;
    bool found = false;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Element not found.\n";
    }
}

int main() {
    int arr[100], n = 0, choice;

    do {
        cout << "MENU";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
