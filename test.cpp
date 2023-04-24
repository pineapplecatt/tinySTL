#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int m[n][n]{0};
    for (int i = 0; i < n; i++) {
        for (int j = n-1;j>=i;j--){
            m[i][j]=1;
        }
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            cout << m[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}