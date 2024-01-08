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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==NULL)return 0;
        queue<TreeNode*>q;
        priority_queue<long long>a;
        q.push(root);
         while(!q.empty()){
            long long sum=0;
            int s=q.size();
            while(s--){
                TreeNode*temp=q.front();
                q.pop();
                sum+=(temp->val);
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
 
             }
             a.push(sum);

         }
         int count=1;
         long long b;
         while(!a.empty()){
             if(count==k){
                return a.top();
                 
             }
             else{
                //  cout<<a.top();
                 a.pop();
             }count++;
                 
         }
         return -1;
        
    }
};
