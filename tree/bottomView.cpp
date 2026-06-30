/*Bottom View of Binary Tree
Difficulty: MediumAccuracy: 54.18%Submissions: 358K+Points: 4Average Time: 45m
You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

Examples :

Input: root = [1, 2, 3, 4, 5, N, 6]
    
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
    
Output: [5, 10, 4, 28, 25]
Explanation: The Green nodes represent the bottom view of below binary tree.
    
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
  public:
    vector<int> bottomView(Node *root) {
        // code here
        unordered_map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int mini=INT_MAX,maxi=INT_MIN;
        while(!q.empty())
        {
            Node* node=q.front().first;
            int col=q.front().second;
            mp[col]=node->data;
            q.pop();
            mini=min(mini,col);
            maxi=max(maxi,col);
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