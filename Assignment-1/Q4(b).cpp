#include<iostream>
using namespace std;
int main(){
    int r1;
    int c1;
    
    cout<<"enter no if rows of matrix a";
    cin>>r1;
    cout<<"enter no of columns of matrix a";
    cin>>c1;
    int r2;
    int c2;
   
    cout<<"enter no of rows of matrix b";
    cin>>r2;
    cout<<"enter no of columns of matrix b";
    cin>>c2;
    int matA[r1][c1];
     int matB[r2][c2];
    int matC[r1][c2];
    if(c1!=r2){
        cout<<"matrix multiplication not possible";
return 0;
    }
        cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> matA[i][j];
        }
    }
     cout << "Enter elements of second matrix:" << endl;
        for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> matB[i][j];
        }
    }
        for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            matC[i][j] = 0;
        }
    }
       for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                matC[i][j] +=matA[i][k] * matB[k][j];
            }
        }
    }   cout << "Resultant matrix:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << matC[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

    

