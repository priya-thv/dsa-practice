#include<bits/stdc++.h>
using namespace std;
int  check(int i,vector<int>&a,int& s,int k,vector<int>&v){
    // int count=0;
    if(i==v.size()){
        if(s==k){
            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
                
            }
            cout<<endl;
            return 1;
        }
        return 0;
    }
    a.push_back(v[i]);
    s+=v[i];
    int l=check(i+1,a,s,k,v);
    a.pop_back();
    s-=v[i];
    int r=check(i+1,a,s,k,v);
    return l+r;
}
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    vector<int>ans;
    int s=0;
    int x=check(0,ans,s,2,v);
    cout<<x; 
}
