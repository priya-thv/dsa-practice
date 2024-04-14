class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi=0;
        stack<int>s;
        for(int i=0;i<=heights.size();++i){
            while(!s.empty() && (i==heights.size() || heights[i]<heights[s.top()])){
                int height=heights[s.top()];
                s.pop();
                int width=(s.empty())? i:i-s.top()-1;
                maxi=max(maxi,height*width);
            }
            s.push(i);
        }
        return maxi;
    }
};
