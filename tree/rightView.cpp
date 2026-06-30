/*Right View of Binary Tree
Difficulty: EasyAccuracy: 65.18%Submissions: 214K+Points: 2Average Time: 20m
Given the root of a binary Tree. Return the right view of the binary tree. The right view of a Binary Tree is the set of nodes visible when the tree is viewed from the right side.

Examples :

Input: root = [1, 2, 3, N, N, 4, 5]
     2_2
Output: [1, 3, 5]
Input: root = [1, 2, 3, 4, N, N, N, N, 5]
     Right-view-in-binary-tree-1
Output: [1, 3, 4, 5]
Input: root = [3]    
  
Output: [3]
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
    void right(Node* root,int level,vector<int>& vec)
    {
        if(!root)
            return;
        if(level==vec.size())
            vec.push_back(root->data);
        right(root->right,level+1,vec);
        right(root->left,level+1,vec);
    }
  public:
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        right(root,0,ans);
        return ans;
    }
};