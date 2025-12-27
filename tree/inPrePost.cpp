/*Inorder , Preorder and Postorder all in one using 1 stack*/
class Solution {
public:
    vector<vector<int>> treeTraversal(TreeNode* root) {
        vector<int> inor, pre, post;
        vector<vector<int>> ans;

        if (!root) return ans;

        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            TreeNode* node = it.first;
            int num = it.second;

            if (num == 1) {
                // Preorder
                pre.push_back(node->data);
                st.push({node, 2});

                if (node->left)
                    st.push({node->left, 1});
            }
            else if (num == 2) {
                // Inorder
                inor.push_back(node->data);
                st.push({node, 3});

                if (node->right)
                    st.push({node->right, 1});
            }
            else {
                // Postorder
                post.push_back(node->data);
            }
        }

        ans.push_back(inor);
        ans.push_back(pre);
        ans.push_back(post);
        return ans;
    }
};

