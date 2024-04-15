class Solution {
public:
    int dfs(TreeNode* root, int currentSum) {
        if (root == nullptr) {
            return 0;
        }
        // Update the current sum
        cout<<currentSum<<endl;
        currentSum = currentSum * 10 + root->val;
        // If it's a leaf node, return the current sum
        if (root->left == nullptr && root->right == nullptr) {
            return currentSum;
        }
        // Recursively calculate the sum for left and right subtrees
        int leftSum = dfs(root->left, currentSum);
        int rightSum = dfs(root->right, currentSum);
        // Return the sum of left and right subtrees
        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
