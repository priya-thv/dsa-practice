class Solution {
public:
    int count(vector<vector<int>>& matrix,int val){
        int n=matrix.size(),m=matrix[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]<=val)count+=m;
            else if(matrix[i][0]<=val){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]<=val)count++;
                }
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size();
        int l=matrix[0][0],r=matrix[n-1][m-1];
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int c=count(matrix,mid);
            if(c>=k){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
