/*257. Binary Tree Paths
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/
class Solution {
    void helper(TreeNode* root,string s,vector<string>& ans)
    {
        if(!root)
        {
            return;
        }
        if(s!="")
            s+="->";
        s+=to_string(root->val);
        if(!root->left && !root->right)
        {
            ans.push_back(s);
            return;
        }
        helper(root->left,s,ans);
        helper(root->right,s,ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);
        return ans;
    }
};