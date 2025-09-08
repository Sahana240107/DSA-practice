/*Given a Binary Tree of size n, You have to count leaves in it. For example, there are two leaves in the following tree*/
class Solution {
  public:
    int countLeaves(Node* root) {
        long count=0;
        if(root==NULL)
            return count;
        if(!root->left && !root->right)//root->left==NULL && root->right==NULL --->leaf node
            count++;
        else
        {
            count+=countLeaves(root->left);
            count+=countLeaves(root->right);
        }
        return count;
    }
};