/*Tree Boundary Traversal
Difficulty: MediumAccuracy: 23.33%Submissions: 563K+Points: 4Average Time: 35m
Given a root of a Binary Tree, return its boundary traversal in the following order:

Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.

Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.

Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.

Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root = [1, N, 2, N, 3, N, 4, N, N] 
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
*/
/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    void leaves(Node* root,vector<int>& l)
    {
        if(!root->left && !root->right)
            l.push_back(root->data);
        if(root->left)
            leaves(root->left,l);
        if(root->right)
            leaves(root->right,l);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        // code here
        if(!root)
            return {};
        vector<int> ans;
        if(root->left || root->right)//push root only if not leaf node
            ans.push_back(root->data);
            
        //left boundary 
        Node* cur=root->left;
        while(cur)
        {
            if(cur->left || cur->right)
                ans.push_back(cur->data);
            if(cur->left)
                cur=cur->left;
            else
                cur=cur->right;
        }
        
        //add leaves
        leaves(root,ans);
        
        //right traversal 
        //use stack to get reverse 
        stack<int> st;
        cur=root->right;
        while(cur)
        {
            if(cur->left || cur->right)
                st.push(cur->data);
            if(cur->right)
                cur=cur->right;
            else
                cur=cur->left;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};