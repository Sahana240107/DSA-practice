/*Inorder without recursion (using stack)*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        if(!root)
            return {};
        vector<int> inorder;
        stack<Node*> st;
        Node* node=root;
        while(true)
        {
            if(node)
            {
                st.push(node);
                node=node->left;
            }
            else
            {
                if(st.empty())
                    break;
                node=st.top();
                st.pop();
                inorder.push_back(node->data);
                node=node->right;
            }
        }
        return inorder;
    }
};