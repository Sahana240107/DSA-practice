/*Inorder Successor in BST
Solved
Difficulty: EasyAccuracy: 34.97%Submissions: 159K+Points: 2
Given a BST, and a reference to a Node k in the BST. Find the Inorder Successor of the given node in the BST. If there is no successor, return -1. 

Examples :

Input: root = [2, 1, 3], k = 2
Output: 3 
Explanation: Inorder traversal : 1 2 3 Hence, inorder successor of 2 is 3.

Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 8     
Output: 10
Explanation: Inorder traversal: 4 8 10 12 14 20 22. Hence, successor of 8 is 10.

*/
class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) {
        // code here
        Node* cur=root;
        int suc=-1;
        while(cur)
        {
            if(cur->data<=k->data)
                cur=cur->right;
            else
            {
                suc=cur->data;
                cur=cur->left;
            }
        }
        return suc;
        
    }
};