class Solution {
public:
    // Helper function to compare two trees
    bool againcheck(TreeNode* root1, TreeNode* root2){
        if (root1 == nullptr && root2 == nullptr)
            return true;
        if (root1 == nullptr || root2 == nullptr)
            return false;
        if (root1->val != root2->val)
            return false;
        return againcheck(root1->left, root2->left) && againcheck(root1->right, root2->right);
    }

    // Main function to check if subRoot is a subtree of root
    bool check(TreeNode* root, TreeNode* subRoot){
        if (root == nullptr)
            return false;
        if (againcheck(root, subRoot))
            return true;
        return check(root->left, subRoot) || check(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return check(root, subRoot);
    }
};
