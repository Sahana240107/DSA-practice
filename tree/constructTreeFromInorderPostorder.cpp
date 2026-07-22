/*106. Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/
class Solution {
    TreeNode* helper(vector<int>& postorder,int ps,int pe,vector<int>& inorder,int is,int ie,unordered_map<int,int>& mp)
    {
        if(ps>pe||is>ie)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=mp[postorder[pe]];
        int numsleft=inRoot-is;
        root->left=helper(postorder,ps,ps+numsleft-1,inorder,is,inRoot-1,mp);
        root->right=helper(postorder,ps+numsleft,pe-1,inorder,inRoot+1,ie,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return helper(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};