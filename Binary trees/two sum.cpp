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

    void preorder(TreeNode*root,vector<int>&c){
        if(!root) return;
        c.push_back(root->val);
        preorder(root->left,c);
        preorder(root->right,c);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>a;
        preorder(root,a);
        for(int i=0;i<a.size()-1;i++){
            for(int j=i+1;j<a.size();j++){
                if(a[i]+a[j]==k){
                    return true;
                }
            }
        }
        return false;
    }
};
