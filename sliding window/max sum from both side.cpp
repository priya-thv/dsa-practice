int Solution::solve(vector<int> &A, int B) {
    int lsum=0;
    int rsum=0;
    for(int i=0;i<B;i++){
        lsum+=A[i];
    }
    int maxsum=lsum;
    int right=A.size()-1;
    for(int i=B-1;i>=0;i--){
        lsum-=A[i];
        rsum+=A[right];
        right--;
        maxsum=max(maxsum,lsum+rsum);
    }
    return maxsum;
}

