/*863. All Nodes Distance K in Binary Tree
Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void fillParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        fillParent(root,parent);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        while(!q.empty())
        {
            int size=q.size();
            if(k==0)    
                break;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    visited[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    visited[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !visited[parent[node]])
                {
                    visited[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
            k--;
        }
        vector<int> ans;
            while(!q.empty())
            {
                ans.push_back(q.front()->val);
                q.pop();
            }
            return ans;
    }
};