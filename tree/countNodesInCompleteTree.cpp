/*222. Count Complete Tree Nodes
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6*/
class Solution {
    int leftTreeHeight(TreeNode* root)
    {
        int count=0;
        while(root)
        {
            count++;
            root=root->left;
        }
        return count;
    }
    int rightTreeHeight(TreeNode* root)
    {
        int count=0;
        while(root)
        {
            count++;
            root=root->right;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int lh=leftTreeHeight(root);
        int rh=rightTreeHeight(root);
        if(lh==rh)
            return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};