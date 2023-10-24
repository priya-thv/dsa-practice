class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> currentLevel(size);
            
            for (int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                
                if (leftToRight) {
                    currentLevel[i] = temp->val;
                } else {
                    currentLevel[size - 1 - i] = temp->val;
                }
                
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            
            leftToRight = !leftToRight;
            result.push_back(currentLevel);
        }
        
        return result;
    }
};
