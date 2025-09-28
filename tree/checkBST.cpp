/*Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/
class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool inorder(Node* T,Node* prev)
    {
        if(T==NULL)
            return true;
        if(!(inorder(T->left,prev)))
            return false;
        if(prev!=NULL && T->data<=prev->data)
            return false;
            prev=T;
        return inorder(T->right,prev);
    }
    bool isBST(Node* root) {
        // Your code here
        Node *prev=NULL;
        return inorder(root,prev);
        
    }
};