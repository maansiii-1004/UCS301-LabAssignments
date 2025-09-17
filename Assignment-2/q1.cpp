#include <iostream>
using namespace std;
void binarysearch(int arr[],int el,int st,int end){
    bool flag=false;
while(st<=end){
    int mid=st+(end-st)/2;
    if(arr[mid]==el){
        flag=true;
        cout<<el<<"found at index"<<mid<<endl;
        break;
    }
    else if(arr[mid]>el){
        end=mid-1;
    }
    else{
        st=mid+1;
    }
}
if(flag==false){
cout<<"element not found in array";
}
}

int main(){
    int n;
    cout<<"enter number of elements of array"<<endl;

    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int el;
    cout<<"enter element to search in array"<<endl;
    cin>>el;
   binarysearch(arr,el,0,n-1);
}