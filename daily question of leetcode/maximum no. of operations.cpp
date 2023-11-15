class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        for(int i=0;i<arr.size();i++){
            if(i==0){
                arr[0]=1;
            }
            else if((arr[i]-arr[i-1])>1  ){
               
                arr[i]=arr[i-1]+1;
            }
        }
        return arr[n-1];

    }
};
