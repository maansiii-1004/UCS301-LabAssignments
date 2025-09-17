
#include<iostream>
using namespace std;
int main(){
    int r;
    int c;
    
    cout<<"enter no if rows of matrix a";
    cin>>r;
    cout<<"enter no of columns of matrix a";
    cin>>c;
    int mat[r][c];
         cout << "Enter elements of  matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    
    for(int i=0;i<r;i++){
    int sumrow=0;
    for(int j=0;j<c;j++){
sumrow+=mat[i][j];
    }
    cout<<"sum of "<<i+1<< "row is"<<sumrow<<endl;
    
    }
     for(int j=0;j<c;j++){
    int sumcol=0;
    for(int i=0;i<r;i++){
sumcol+=mat[i][j];
    }
     cout<<"sum of "<<j+1<< "col is"<<sumcol<<endl;
}
    return 0;
}