class Solution {
public:
    void update(int i,int val,vector<int>&b){
        while(i<b.size()){
            b[i]+=val;
            i+=i&(-i);
        }
    }
    int sum(int i,vector<int>&b){
        int s=0;
        while(i>0){
            s+=b[i];
            i-=i&(-i);
        }
        return s;
    }
    vector<int> processQueries(vector<int>& queries, int m) {
        int n=queries.size();
        int t=n+m+1;
        vector<int>b(t);
        map<int,int>hash;
        for(int i=1;i<=m;i++){
            update(n+i,1,b);
            hash[i]=n+i;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=sum(hash[queries[i]],b)-1;
            update(hash[queries[i]],-1,b);
            update(n-i,1,b);
            hash[queries[i]]=n-i;
        }
        return ans;
    }
};  
