#include<bits/stdc++.h>
using namespace std;
time limit exceed
bool safe(int i, int j, int n, int m,int **matrix,vector<vector<bool>>&v) {
    return (i >= 0 && j >= 0 && i < n && j < m && matrix[i][j]==1 && v[i][j]!=1 );
}

void dfs(int i,int j,int **matrix, int n, int m, int x, int y, vector<vector<bool>>&v,int count,int &mini){
     if (i == x && j == y) {
        mini = min(mini, count);
        return;
    }
    v[i][j]=1;
    // left
    if(safe(i,j-1,n,m,matrix,v)){
        dfs(i,j-1,matrix,n,m,x,y,v,count,mini);
    }
    // right
    if(safe(i,j+1,n,m,matrix,v)){
        dfs(i,j+1,matrix,n,m,x,y,v,count,mini);
    }
    // down
    if(safe(i-1,j,n,m,matrix,v)){
        count++;
        dfs(i-1,j,matrix,n,m,x,y,count,mini);
        
    }
    // up
    if(safe(i+1,j,n,m,matrix,v)){
         count++;
        dfs(i+1,j,matrix,n,m,x,y,v,count,mini);
       
    }
  
    v[i][j] = 0;
}

int minCostToDestination(int **matrix, int n, int m, int x, int y)
{
    
    vector<vector<bool>>v(n,vector<bool>(m,0));
    int count=0;
    int mini=INT_MAX;
    int i=0,j=0;
    dfs(i,j ,matrix, n, m, x, y, v, count, mini);
    if(mini==INT_MAX){
        return -1;
    }
    return mini;
}

