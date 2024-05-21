#include <bits/stdc++.h>
using namespace std;
int sum(int i, vector<int>& b) {
    int s = 0;
    while (i > 0) {
        s += b[i];
        i -= i & (-i);
    }
    return s;
}
int update(int i,int x,vector<int>& ba){
    while(i<=10){
        ba[i]+=x;
        i+=i & (-i);
    }
}
void create(vector<int>& ba, vector<int>& v)
{
    for (int i = 1; i <= 10; i++)
    {  
        update(i,v[i-1],ba);
    }
}


int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    vector<int> ba(10, 0);
    create(ba, v);
    for(int i=0;i<10;i++){
        cout<<ba[i]<<" ";
    }
}

