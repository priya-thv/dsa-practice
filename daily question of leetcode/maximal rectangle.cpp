// class Solution {
// public:
//     int maximalRectangle(vector<vector<char>>& matrix) {
//         if(matrix.size()==0){
//             return 0;
//         }

//         if(matrix.size()==1 && matrix[0][0]=='1'){
//             return 1;
//         }
//         else{
//              return 0;
//         }
        
//         vector<vector<int>>v(matrix.size(),vector<int>(matrix[0].size(),0));
//         for(int i=0;i<matrix.size();i++){
//             int psum=0;
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j]=='1'){
//                     v[i][j]=psum+1;
//                 }else if(matrix[i][j]=='0'){
//                     v[i][j]=0;
//                     psum=0;
//                 }
//             }
//         }
//         vector<vector<int>>t(matrix.size(),vector<int>(matrix[0].size(),0));
//         for(int i=0;i<matrix[0].size();i++){
//             int psum=0;
//             for(int j=0;j<matrix.size();j++){
//                 if(matrix[i][j]=='1'){
//                     t[i][j]=psum+1;
//                 }else if(matrix[i][j]=='0'){
//                     t[i][j]=0;
//                     psum=0;
//                 }
//             }
//         }

//         vector<pair<int,int>>row(matrix.size());
//         vector<pair<int,int>>col(matrix[0].size());
//         int max1=0,max2=0;
//         stack<int>s;
        
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(s.empty()){
//                     s.push({})
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>>mt;
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        mt=vector<vector<int>>(matrix.size(),vector<int>(matrix[0].size()));
        int ans=0;
       for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1')
                mt[i][j]=1,ans=1;
                else mt[i][j]=0;
            }
       }
        
        for(int i=0;i<matrix.size();i++){
            ans=max(ans,mt[i][0]);
            for(int j=1;j<matrix[i].size();j++){
                if(mt[i][j]==1){
                    mt[i][j]+=mt[i][j-1];
                    ans=max(ans,mt[i][j]);
                }
                else ans=max(ans,mt[i][j-1]);
            }
        }
        
        for(int i=0;i<mt.size();i++){
            for(int j=0;j<mt[i].size();j++){
                if(mt[i][j]==0)continue;
                int n=1,mn=mt[i][j];
                for(int r=i+1;r<matrix.size();r++){
                    if(mt[r][j]==0)break;
                    mn=min(mn,mt[r][j]);
                    n++;
                    ans=max(ans,n*mn);
                }
            }
        }
        return ans;
    }
};
