/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
*/
class Solution {
    bool helper(TreeNode* t1,TreeNode* t2)
    {
        if(!t1 && !t2)
            return true;
        else if(!t1 || !t2)
            return false;
        else if(t1->val !=t2->val)
            return false;
        return helper(t1->left,t2->right)&& helper(t1->right,t2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return helper(root->left,root->right);
    }
};