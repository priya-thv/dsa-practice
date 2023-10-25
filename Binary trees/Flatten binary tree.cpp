class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        vector<TreeNode*> nodes;
        preorder(root, nodes);

        TreeNode* current = root;
        for (int i = 1; i < nodes.size(); ++i) {
            current->left = nullptr;
            current->right = nodes[i];
            current = current->right;
        }
    }

    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        
        nodes.push_back(root);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
};
