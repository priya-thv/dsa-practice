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
    void dfs(TreeNode* root, string path, vector<string>& paths) {
        if (!root) return;

        path += (char)('a' + root->val);

        if (!root->left && !root->right) { // Leaf node
            reverse(path.begin(), path.end());
            paths.push_back(path);
            return;
        }

        dfs(root->left, path, paths);
        dfs(root->right, path, paths);
    }

    string smallestLexicographical(vector<string>& paths) {
        if (paths.empty()) return "";

        return *min_element(paths.begin(), paths.end());
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> paths;
        dfs(root, "", paths);
        return smallestLexicographical(paths);
    }
};
