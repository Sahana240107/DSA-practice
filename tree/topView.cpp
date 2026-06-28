/*Top View of Binary Tree
Difficulty: MediumAccuracy: 38.43%Submissions: 468K+Points: 4Average Time: 45m
You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view. 
Examples:

Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
 
Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.

*/

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        if(!root)
            return {};
        int mini=INT_MAX,maxi=INT_MIN;
        unordered_map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            Node* node=q.front().first;
            int col=q.front().second;
            q.pop();
            maxi=max(maxi,col);
            mini=min(mini,col);
            if(mp.find(col)==mp.end())
                mp[col]=node->data;
            if(node->left)
                q.push({node->left,col-1});
            if(node->right)
                q.push({node->right,col+1});
        }
        vector<int> ans;
        for(int i=mini;i<=maxi;i++)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};