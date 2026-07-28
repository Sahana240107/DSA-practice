/*Ceil in BST

Given a root binary search tree and an integer x , find the Ceil of x in the tree.

Ceil(x) is a number that is either equal to x or is immediately greater than x. If Ceil could not be found, return -1.

Examples:

Input: root = [5, 1, 7, N, 2, N, N, N, 3], x = 3

Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ceil=-1;
        Node* cur=root;
        while(cur)
        {
            if(cur->data==x)
                return x;
            else if(cur->data<x)
                cur=cur->right;
            else
            {
                ceil=cur->data;
                cur=cur->left;
            }
        }
        return ceil;
    }
};
