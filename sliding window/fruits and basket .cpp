class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int ans=0;
        int maxi=0;
        unordered_map<int,int>mp;
        while(r<fruits.size()){
            mp[fruits[r]]++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)mp.erase(fruits[l]);
                l++;
            }
            ans=r-l+1;
            maxi=max(maxi,ans);
            r++;
        }
        return maxi;
    }
};

or

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0;
        int r=0;
        int ans=0;
        int maxi=0;
        unordered_map<int,int>mp;
        while(r<fruits.size()){
            mp[fruits[r]]++;
            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0)mp.erase(fruits[l]);
                l++;
            }
            if(mp.size()<=2){
               ans=r-l+1;
               maxi=max(maxi,ans);
            }
            r++;
        }
        return maxi;
    }
};
