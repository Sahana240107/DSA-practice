/*Given the root of a Binary Tree, find the vertical traversal of the tree starting from the leftmost level to the rightmost level.

Note: If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

Examples:

Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, N, 8, N, 9, N, 10, 11, N]
                    
Output: [[4], [2], [1, 5, 6, 11], [3, 8, 9], [7], [10]]*/
class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        unordered_map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        int mini=INT_MAX;
        int maxi=INT_MIN;
        while(!q.empty())
        {
            Node* node=q.front().first;
            int col=q.front().second;
            q.pop();
            maxi=max(maxi,col);
            mini=min(mini,col);
            mp[col].push_back(node->data);
            if(node->left)
                q.push({node->left,col-1});
            if(node->right)
                q.push({node->right,col+1});
        }
        vector<vector<int>> ans;
        for(int i=mini;i<=maxi;i++)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};

//LEETCODE VERSION

/*Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.*/