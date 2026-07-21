/*Burning Tree
Solved
Difficulty: HardAccuracy: 53.53%Submissions: 150K+Points: 8
Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.

Note: The tree contains unique values.

Examples : 

Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
  
Output: 3
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.
*/

class Solution {
    void markParents(Node* root,unordered_map<Node*,Node*>& parent)
    {
        if(!root)
            return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node=q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    Node* findTarget(Node* root,int target)
    {
        if(!root)
            return root;
        if(root->data==target)
            return root;
        Node* left=findTarget(root->left,target);
        if(left)
            return left;
        return findTarget(root->right,target);
    }
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*,Node*> parent;
        markParents(root,parent);
        Node* start=findTarget(root,target);
        queue<Node*> q;
        q.push(start);
        unordered_map<Node*,bool> visited;
        visited[start]=true;
        int time=0;
        while(!q.empty())
        {
            int size=q.size();
            bool flag=false;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    flag=true;
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    flag=true;
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]])
                {
                    flag=true;
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
            if(flag)
                time++;
        }
        return time;
    }
};