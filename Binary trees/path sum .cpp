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
    bool dfs(TreeNode* root, int target,int sum){
        if(root==NULL){
            return false;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==target){
                return true;
            }
        }
        bool left=dfs(root->left,target,sum);
        bool right=dfs(root->right,target,sum);
        if(left || right){
            return true;
        }
       return false;
    }
    bool hasPathSum(TreeNode* root, int target) {
        return dfs(root,target,0);

    }
};
