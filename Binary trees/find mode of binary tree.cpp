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

    void inorder(TreeNode* root,vector<int>&a){
        if(!root) return;

        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>a;
        vector<int>b;
        inorder(root,a);
        map<int,int>m;
        for(auto i:a){
            m[i]++;
        }
        int j=1;
        for(auto i:m){
            if(i.second>j){
                j=i.second;
            }
        }
        for(auto i:m){
            if(i.second==j){
                b.push_back(i.first);
            }
        }
        return b;
    }
};
