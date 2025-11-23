/*Given a binary tree, you have to return the size of it. Size of binary tree is defined as number of nodes in it.

Examples:

Input:      
       1
     /  \
    2    3
Output: 3
Explanation: There are three nodes in given binary tree.
*/
class Solution {
  public:
    int getSize(Node* node) {
        int n=0;
        if(node==NULL)
            return 0;
        return 1+getSize(node->left)+getSize(node->right)
    }
};