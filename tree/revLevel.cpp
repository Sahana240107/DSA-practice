/*Given the root of a binary tree, return the bottom-up level order traversal of its nodes' 
values. (i.e., from left to right, level by level from leaf to root).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
*/
class Solution {
public:
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> levelOrder;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> lvl;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            levelOrder.push_back(lvl);
        }
        reverse(levelOrder.begin(),levelOrder.end());
        return levelOrder;
    }
};