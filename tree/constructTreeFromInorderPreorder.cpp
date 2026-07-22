/*105. Construct Binary Tree from Preorder and Inorder Traversal
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/
class Solution {
    TreeNode* helper(vector<int>& preorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int>& mp)
    {
        if(ps>pe||is>ie)
            return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int inRoot=mp[preorder[ps]];
        int numsLeft=inRoot-is;
        root->left=helper(preorder,ps+1,ps+numsLeft,inorder,is,inRoot-1,mp);
        root->right=helper(preorder,ps+numsLeft+1,pe,inorder,inRoot+1,ie,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;
        return helper(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
    }
};