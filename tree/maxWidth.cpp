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
//LC Max Width 
/*662. Maximum Width of Binary Tree
Medium
Topics
premium lock icon
Companies
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
Example 3:


Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).
 

*/