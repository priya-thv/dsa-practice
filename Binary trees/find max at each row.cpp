/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>a;
        if(root==NULL)return a;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode*temp=q.front();
            q.pop();
           maxi=max(maxi,temp->val);
          
            if(temp->left){
               q.push(temp->left);
            }
            if(temp->right){
               q.push(temp->right);
            }
            
            }
         a.push_back(maxi);
            
        }
        return a;
    }
};
