/*Given a Binary Search Tree and a node value X, find if the node with value X is present in the BST or not.
*/
bool search(Node* root, int x) {
    if(root==NULL)
        return false;
    if(root->data==x)
        return true;
    if(root->data>x)
        return search(root->left,x);
    else
        return search(root->right,x);
}