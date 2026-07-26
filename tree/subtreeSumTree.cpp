/*Sum Tree
Solved
Difficulty: MediumAccuracy: 37.17%Submissions: 290K+Points: 4
Given the root of a Binary Tree with n nodes, check whether it is a Sum Tree and return true if it is, otherwise return false.

A Sum Tree is a Binary Tree in which the value of every non-leaf node is equal to the sum of all nodes present in its left and right subtrees. An empty tree and a leaf node are also considered Sum Trees.

Examples:

Input: root[] = [3, 1, 2]
 
Output: true
Explanation: The sum of left subtree and right subtree is 1 + 2 = 3, which is the value of the root node. Therefore, the given binary tree is a sum tree.
Input: root[] = [10, 20, 30, 10, 10]
 
Output: false
Explanation: The given tree is not a Sum Tree. For the root node, the sum of nodes in the left and right subtrees is 40 + 30 = 70, which is not equal to the root value 10.
*/

class Solution {
    int helper(Node* node)
    {
        if(!node)
            return 0;
        if(!node->left && !node->right)
            return node->data;
        int left=helper(node->left);
        if(left==-1)
            return -1;
        int right=helper(node->right);
        if(right==-1)
            return -1;
        if(node->data!=left+right)
            return -1;
        return node->data+left+right;
    }
  public:
    bool isSumTree(Node* node) {
        // code here
        if(!node)
            return true;
        return helper(node)!=-1;
    }
};