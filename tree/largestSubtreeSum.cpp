/*Largest Subtree Sum
Solved
Difficulty: MediumAccuracy: 54.83%Submissions: 30K+Points: 4
Given a binary tree, find subtree with maximum sum in the tree and return its sum.

Examples:

Input: root[] = [10, 8, 2, 3, 5, N, N]    
        
Output: 28
Explanation: 
As all the tree elements are positive, the largest subtree sum is equal to sum of all tree elements.
Input: root[] = [1, -2, 3, 4, 5, -6, 2]
        
Output: 7
Explanation: 
Subtree with largest sum is : 
         
The whole tree sum is also 7. 
*/
class Solution {
    int ans=INT_MIN;
    int maxSum(Node* root)
    {
        if(!root)
            return 0;
       int left=maxSum(root->left);
       int right=maxSum(root->right);
        ans=max(ans,left+right+root->data);
        return left+right+root->data;
    }
  public:
    int maxSubtreeSum(Node* root) {
        // code here
        maxSum(root);
        return ans;
    }
};
