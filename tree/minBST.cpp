/*Given the root of a Binary Search Tree. Your task is to find the minimum element in this given BST.

Examples

Input: root = [5, 4, 6, 3, N, N, 7, 1]
ex-1
Output: 1
Explanation: The minimum element in the given BST is 1.
*/
class Solution {
  public:
    int minValue(Node* root) {
        // code here
        if(root->left==NULL)
            return root->data;
        return minValue(root->left);
        
    }
};