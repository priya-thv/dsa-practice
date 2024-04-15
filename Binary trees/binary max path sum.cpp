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
    int maxsum=INT_MIN;
    int dfs(TreeNode* root){
        if(root==NULL)return 0;

        int leftsum=max(dfs(root->left),0);
        int rightsum=max(dfs(root->right),0);
        maxsum=max(maxsum,leftsum+rightsum+root->val);
        return max(leftsum, rightsum) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int t=dfs(root);
        return maxsum;
    }
};
