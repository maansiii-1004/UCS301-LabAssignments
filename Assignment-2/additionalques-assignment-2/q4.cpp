#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int main(){
      
     int n;
    cout<<"enter number of elements of array"<<endl;

    cin>>n;
    int arr[n];
    cout<<"enter elements of array ,only 0,1,2 allowed in array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high){
    if(arr[mid]==0){
        swap(arr[low],arr[mid]);
        low++;
        mid++;
    }
    else if(arr[mid]==1){
        mid++;
    }
    else{
        swap(arr[high],arr[mid]);
        high--;
    }
}
 cout<<"sorted array is"<<endl;
    for(int i=0;i<n;i++){
       cout<<arr[i]<<" ";

    }
    return 0;
}