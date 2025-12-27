/*Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes at any level.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7]
          
Output: 4*/
class Solution {
  public:
    int maxWidth(Node* root) {
        if(!root)
            return 0;
        int maxi=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            maxi=max(maxi,size);
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return maxi;
    }
};