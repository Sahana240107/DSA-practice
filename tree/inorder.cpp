/*Given a Binary Tree, your task is to return its In-Order Traversal.

An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).*/


class Solution {
  public:
     // Function to return a list containing the inorder traversal of the tree.
    void helper(Node *root,vector<int> &res)
    {
        if(root==NULL)
            return;
        helper(root->left,res);
        res.push_back(root->data);
        helper(root->right,res);
    }
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
};