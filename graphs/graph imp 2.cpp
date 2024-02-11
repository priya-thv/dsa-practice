#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N=1e5+2,MOD =1e9+7;

// representation of graphs
vi adj[N];

signed main(){
    int n,m;
    cin>>n>>m;
    vvi adjm(n+1,vi(n+1,0));

    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"adjacent matrix"<<endl;
    rep(i,1,n+1){
        rep(j,1,n+1){
            cout<<adjm[i][j]<<" ";
           
        } cout<<endl;
    }
    if(adjm[3][7]==1)cout<<" edge is present";
    else cout<<"not present";
    cout<<endl;

    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    cout<<"adjance list of the above graphs is given by:";
    rep(i,1,n+1){
        cout<<i<<"->";
        for(int x:adj[i])
        cout<<x<<" ";

        cout<<endl;
    }
}
