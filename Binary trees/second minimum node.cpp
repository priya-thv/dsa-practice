

class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& values) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, values);
        values.push_back(root->val);
        inorderTraversal(root->right, values);
    }

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> a;
        inorderTraversal(root, a);
        sort(a.begin(),a.end());
        int b=a[0];
        int c;
        for(int i=1;i<a.size();i++){
            if(a[i]>b){
                c=a[i];
              return c;
            }
        }
        return -1;
    }
};
