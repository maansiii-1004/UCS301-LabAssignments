
#include <iostream>
using namespace std;

int countPairs(int arr[], int k) {
    int n=5;
    int cnt = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            
           
            if (abs(arr[i] - arr[j]) == k) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

int main() {
    
     int n;
    cout<<"enter number of elements of array"<<endl;

    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   
    int k;
    cout<<"enter diff in pairs"<<endl;
cin>>k;
    cout << countPairs(arr, k);
    return 0;
}