class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        if(height.size()==2){
            int s=min(height[0],height[1]);
            return s*1;
        }
        int maxi=0;
        while(i<=j){
            if(height[i]<height[j]){
               int t=min(height[i],height[j]);
               maxi=max(maxi,t*(j-i));
               i++;
            }
            else if(height[i]>=height[j]){
                int x=min(height[i],height[j]);
                maxi=max(maxi,x*(j-i));
                j--;
            }
        }
        return maxi;
    }
};
