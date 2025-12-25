/*Given a root binary tree and the task is to find the spiral order traversal of the tree 
and return the list containing the elements.

Spiral Order Traversal mean: Starting from level 0 for root node, for all the even levels
 we print the node's value from right to left and for all the odd levels we print the node's value from left to right.

*/
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        if(!root)
            return {};
        int lvl=0;
        vector<int> levelOrder;
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
            if(lvl%2==0)
                reverse(level.begin(),level.end());
            levelOrder.insert(levelOrder.end(),level.begin(),level.end());
            lvl++;
        }
        return levelOrder;
    }
};
//alternate solution
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        if(!root)
            return {};
        bool evenlevel=true;
        vector<int> levelOrder;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            deque<int> level;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                if(evenlevel)
                    level.push_front(node->data);
                else
                    level.push_back(node->data);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            for(int x:level)
            {
                levelOrder.push_back(x);
            }
            evenlevel=!evenlevel;
        }
        return levelOrder;
    }
};