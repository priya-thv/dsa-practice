class Solution {
public:
    int findChampion(vector<vector<int>>& arr) {
        int col = arr[0].size(); 
        cout<<col;
        vector<int> v;
        int count = 0;
        int c = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < col; j++) { 
                if (count == col-1) {
                    v.push_back(c);
                    c = 0;
                    count=0;
                }
                else{
                    c = c + arr[i][j];
                count++;
                }
            }
           
        }
        int maxIndex = 0; 
        for (int i = 0; i < v.size(); i++) {
            
            if (v[i] > v[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex; 
    }
};
