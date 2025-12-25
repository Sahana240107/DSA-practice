/*Given the root of a Binary Tree, your task is to return its Level Order Traversal.

Note: A level order traversal is a breadth-first search (BFS) of the tree. It visits nodes level by level, 
starting from the root, and processes all nodes from left to right within each level before moving to the next.*/
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
        
    }
};