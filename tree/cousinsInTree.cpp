/*993. Cousins in Binary Tree
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
*/
class Solution {
    bool findParentDepth(TreeNode* root,int x,int parent,int depth,int& ansParent,int& ansDepth)
    {
        if(!root)
            return false;
        if(root->val==x)
        {
            ansParent=parent;
            ansDepth=depth;
            return true;
        }
        if(findParentDepth(root->left,x,root->val,depth+1,ansParent,ansDepth))
            return true;
        return findParentDepth(root->right,x,root->val,depth+1,ansParent,ansDepth);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int parentx=-1,depthx=0,parenty=-1,depthy=0;
        findParentDepth(root,x,-1,0,parentx,depthx);
        findParentDepth(root,y,-1,0,parenty,depthy);
        return (parentx!=parenty && depthx==depthy)?true:false;
    }
};

//BFS
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            bool xflag=false,yflag=false;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->val==x)
                    xflag=true;
                if(node->val==y)
                    yflag=true;
                //check if siblings
                if(node->left && node->right)
                {
                    int left=node->left->val;
                    int right=node->right->val;
                    if((left==x && right==y)||(left==y && right==x))
                        return false;
                }
                if(node->left)  
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(xflag&&yflag)
                return true;
            if(xflag||yflag)
                return false;
        }
        return false;
    }
};