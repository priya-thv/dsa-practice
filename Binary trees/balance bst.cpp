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
    void inorder(TreeNode* root,vector<int>&t){
        if(root==NULL)return;
         
        inorder(root->left,t); 
        t.push_back(root->val);
        inorder(root->right,t);
    }

    TreeNode*create(vector<int>&a,int start,int end){
       if(start>end)return NULL;

        int mid=start+(end-start)/2;
        TreeNode*root=new TreeNode(a[mid]);
        root->left=create(a,start,mid-1);
        root->right=create(a,mid+1,end);
          return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>a;
        inorder(root,a);

        return create(a,0,a.size()-1);
    }
};
