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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(root==NULL)return 0;
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,char>>q;
        q.push({root,'R'});
        while(!q.empty()){
            TreeNode*front=q.front().first;
            char c=q.front().second;
            q.pop();
            if(front->left!=NULL ){
                q.push({front->left,'l'});
            }
            if(front->right!=NULL ){
                q.push({front->right,'r'});
            }
            else if(front->left==NULL && front->right==NULL && c=='l'){
                sum+=front->val;
            }
            
        }
        return sum;
    }
};
