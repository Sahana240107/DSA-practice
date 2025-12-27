/*Input:
 root  -->     1
             /   \
            3     2
           /
          4
Output: 3
Explanation:
Maximum depth is between nodes 1 and 4, which is 3.*/
class Solution {
  public
    int maxDepth(Node *root) {
        if(root==nullptr)
            return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};