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
    void pre(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        v.push_back(root->val);
        pre(root->left,v);
        pre(root->right,v);
    }
       bool isUnivalTree(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        vector<int> a;
        pre(root, a);
        bool flag = true; // Initialize to true
        int b = a[0];

        for (int i = 1; i < a.size(); i++) {
            if (a[i] != b) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
        
  
