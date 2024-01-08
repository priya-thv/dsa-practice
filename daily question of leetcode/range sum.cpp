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
    void array(TreeNode* root,vector<int>&a){
        if(root==NULL)return;

        a.push_back(root->val);
        array(root->left,a);
        array(root->right,a);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int>a;
        array(root,a);
        cout<<a.size();
        int sum=0;
        for(int i=0;i<a.size();i++){
            if(a[i]>=low && a[i]<=high)sum=sum+a[i];
        }
        return sum;
       
        
    }
};
