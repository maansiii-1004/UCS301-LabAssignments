
#include<iostream>
using namespace std;
int main(){
    int r1;
    int c1;
    
    cout<<"enter no if rows of matrix a";
    cin>>r1;
    cout<<"enter no of columns of matrix a";
    cin>>c1;
    int matA[r1][c1];
         cout << "Enter elements of  matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> matA[i][j];
        }
    }
    int matB[c1][r1];
        for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++){
            matB[i][j]=matA[j][i];
        }
    }
    cout<<"transpose of matrix is"<<endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++){
cout<<matB[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}