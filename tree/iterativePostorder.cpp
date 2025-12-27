/*Using 2 stack*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left)
                st1.push(node->left);
            if(node->right)
                st1.push(node->right);
        }
        vector<int> postorder;
        while(!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};

/*Using 1 stack*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*> st;
        vector<int> post;
        Node* cur=node;
        while(cur!=NULL|| !st.empty())
        {
            if(cur)
             {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                Node* temp=st.top()->right;
                if(temp==NULL)
                {
                    temp=st.top();
                    st.pop();
                    post.push_back(temp->data);
                    while(!st.empty() && temp==st.top()->right)
                    {
                        temp=st.top();
                        st.pop();
                        post.push_back(temp->data);
                    }
                }
                else
                    cur=temp;
            }
        }
         return post;
    }
};