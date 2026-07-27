/*Morris Preorder Traversal*/
vector<int> preorder;
        TreeNode* cur=root;
        while(cur)
        {
            if(!cur->left)
            {
                preorder.push_back(cur->val);
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
                    preorder.push_back(cur->val);
                    cur=cur->left;
                }
                else
                {
                    prev->right=NULL;
                    cur=cur->right;
                }
            }
        }
        return preorder;