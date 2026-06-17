/*You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example 1:

Input: root = [4,2,7,1,3], val = 5
Output: [4,2,7,1,3,5]*/

//Recursive
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        else if(root->val>val)
            root->left=insertIntoBST(root->left,val);
        else
            root->right=insertIntoBST(root->right,val);
        return root;
        
    }
};

//Iterative
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        if(!root)
            return node;
        TreeNode* cur=root;
        while(true)
        {
            if(cur->val>val)
            {
                if(!cur->left)
                {
                    cur->left=node;
                    break;
                }
                cur=cur->left;
            }
            else
            {
                if(!cur->right)
                {
                    cur->right=node;
                    break;
                }
                cur=cur->right;
            }
        }
        return root;
    }
};