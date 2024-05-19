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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<preorder.size();i++){
            mp[inorder[i]]=i;

        }
        TreeNode*root=create(preorder,0,preorder.size()-1,inorder,0,inorder.size(),mp);
        return root;
    }
    TreeNode*create(vector<int>&preorder, int preStart, int preEnd, vector<int> &inorder,
    int inStart, int inEnd, map<int,int> &mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode*root=new TreeNode(preorder[preStart]);
        int inroot=mp[root->val];
        int numsLeft=inroot-inStart;
        root->left = create(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inroot-1,mp);
        root->right = create(preorder,preStart+numsLeft+1,preEnd,inorder,inroot+1,inEnd,mp);
        return root;
    }
};
