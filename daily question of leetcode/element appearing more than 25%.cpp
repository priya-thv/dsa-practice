class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int b=0;
        int n =arr.size();
        int y=(n*25)/100;
        map<int,int>mp;
        for(auto x:arr){
            mp[x]++;
        }  
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]>y){
                b=arr[i];
            }
        }
        
        return b;
    }
};
