#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int>v;
    if(root==NULL){
        return v;
    }
    queue<BinaryTreeNode<int>* >q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *t=q.front();
        q.pop();
        v.push_back(t->val);
        if(t->left!=NULL){
            q.push(t->left);
        }
        if(t->right!=NULL){
            q.push(t->right);
        }

    }
    return v;
}
