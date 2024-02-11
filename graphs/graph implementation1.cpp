#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout<<"enter the no. of nodes ;";

    cin >> n ;
    cout<<"enter the no. of edges ;";
    cin>>m;

    vector<vector<int>> v(n, vector<int>(m, 0));

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x][y]=1;
        v[y][x]=1;
       
    }

    // Print the matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    // Display non-zero elements in each row
    for(int i = 0; i < n; i++){
        cout << i << "-> ";
        for(int j = 0; j < m; j++){
            if(v[i][j] == 1){
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
