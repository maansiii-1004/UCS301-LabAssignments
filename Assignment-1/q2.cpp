#include <iostream>
using namespace std;

int main() {
   int n;
   cout<<"enter number of elements in array";
   cin>>n;
int arr[n];
cout<<"enter elements of array";
for(int i=0;i<n;i++){
    cin>>arr[i];
}

    int unique[100]; 
    int size = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

    
        for (int j = 0; j < size; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = true;
                break;
            }
        }

        
        if (!isDuplicate) {
            unique[size] = arr[i];
            size++;
        }
    }

    
    cout << "Unique array: ";
    for (int i = 0; i < size; i++) {
        cout << unique[i] << " ";
    }
    cout << endl;

    return 0;
}
