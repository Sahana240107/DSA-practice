/*Morris Inorder Traversal*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur=root;
        while(cur)
        {
            if(cur->left==NULL)//root or no left
            {
                inorder.push_back(cur->val);
                cur=cur->right;
            }
            else
            {
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur) //rightmost node of left subtree 
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)//make thread
                {
                    prev->right=cur;
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;//remove thread
                    inorder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};