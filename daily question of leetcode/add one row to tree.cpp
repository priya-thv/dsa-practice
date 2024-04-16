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
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if( depth==1){
            TreeNode*ptr=new TreeNode(val);
            ptr->left=root;
            return ptr;
        }
        int count=1;
        queue<pair<TreeNode*,int>>q;
        q.push({root,count});

        while(!q.empty()){
            TreeNode*front=q.front().first;
            int t=q.front().second;
            q.pop();
            if(t==depth-1){
                TreeNode*ptr=front->left;
                front->left=new TreeNode(val);
                front->left->left=ptr;

                ptr=front->right;
                front->right=new TreeNode(val);
                front->right->right=ptr;
            }else{
                // count++;
                // if(front->left) 
                // q.push({front->left,count});

                // if(front->right){
                //     q.push({front->right,count});
                // }
                 if (front->left) q.emplace(front->left, t+1);
                if (front->right) q.emplace(front->right, t+1);
            }
           
        }
         return root;
    }
};
