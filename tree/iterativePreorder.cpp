/*Preorder without recursion*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> pre;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node=st.top();
            st.pop();
            pre.push_back(node->val);
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
        }
        return pre;
    }
};