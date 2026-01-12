/*Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
*/
class Solution {
    TreeNode* buildTree(vector<int>& num,int left,int right)
    {
        if(left>right)
            return NULL;
        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(num[mid]);
        root->left=buildTree(num,left,mid-1);
        root->right=buildTree(num,mid+1,right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
};