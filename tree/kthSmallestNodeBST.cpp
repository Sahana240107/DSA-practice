/*230. Kth Smallest Element in a BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
       TreeNode* cur=root;
       int count=0;
       int ans=-1;
       while(cur)
       {
            if(!cur->left)
            {
                count++;
                if(count==k)
                    ans=cur->val;
                cur=cur->right;
            }
            else
            {
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur)
                    prev=prev->right;
                if(!prev->right)
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;
                    count++;
                    if(count==k)
                        ans=cur->val;
                    cur=cur->right;
                }
            }
       }
       return ans;
    }
};