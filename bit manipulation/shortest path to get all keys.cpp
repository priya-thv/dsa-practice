class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        int totalKeys = 0;
        int startRow, startCol;
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char c = grid[i][j];
                if(c == '@') {
                    startRow = i;
                    startCol = j;
                }
                if(c >= 'a' && c <= 'f') {
                    totalKeys = max(totalKeys, c - 'a' + 1);
                }
            }
        }
        
        vector<int> start = {0, startRow, startCol};
        queue<vector<int>> q;
        unordered_set<string> visited;
        visited.insert(to_string(0) + " " + to_string(startRow) + " " + to_string(startCol));
        q.push(start);
        int step = 0;
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                vector<int> curr = q.front();
                q.pop();
                int keysCollected = curr[0];
                int row = curr[1];
                int col = curr[2];
                
                if(keysCollected == (1 << totalKeys) - 1) {
                    return step;
                }
                
                for(auto& d : dirs) {
                    int newRow = row + d[0];
                    int newCol = col + d[1];
                    int newKeysCollected = keysCollected;
                    
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                        char cell = grid[newRow][newCol];
                        
                        if(cell == '#') continue;
                        
                        if(cell >= 'a' && cell <= 'f') {
                            newKeysCollected |= 1 << (cell - 'a');
                        }
                        
                        if(cell >= 'A' && cell <= 'F' && ((keysCollected >> (cell - 'A')) & 1) == 0) {
                            continue;
                        }
                        
                        string nextState = to_string(newKeysCollected) + " " + to_string(newRow) + " " + to_string(newCol);
                        if(!visited.count(nextState)) {
                            visited.insert(nextState);
                            q.push({newKeysCollected, newRow, newCol});
                        }
                    }
                }
            }
            step++;
        }
        
        return -1; // No 
    }
};
