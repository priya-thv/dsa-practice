// not fully correct
#include <bits/stdc++.h> 

using namespace std;

/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

// Inorder traversal to populate a vector with elements of the tree
void inorder(vector<int>& a, BinaryTreeNode<int> *root) {
    if (root == NULL) {
        return;
    }
    inorder(a, root->left);
    a.push_back(root->data);
    inorder(a, root->right);
}

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    if (root == NULL) {
        return -1; // Return -1 if root is NULL
    }
    
    // Perform inorder traversal to get all node values in a vector
    vector<int> a;
    inorder(a, root);
    
    // Find the maximum value in the tree
    int n = *max_element(a.begin(), a.end());

    // Create a parent array to store the parent nodes of each node
    vector<int> parent(n + 1, -1);

    // Perform BFS to fill the parent array
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front->left != NULL) {
            parent[front->left->data] = front->data;
            q.push(front->left);
        }
        if (front->right != NULL) {
            parent[front->right->data] = front->data;
            q.push(front->right);
        }
    }

    vector<int>ans;
	int currnode=targetNodeVal;
	ans.push_back(targetNodeVal);
	while(currnode!=-1){
		currnode=parent[currnode];
		ans.push_back(currnode);
	}
    return ans[k];
    // return ancestor;
}
