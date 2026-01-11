/*Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.*/
 
class Solution {
    ListNode* middleNode(ListNode* head,ListNode* tail)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=tail && fast->next!=tail)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    TreeNode* buildBST(ListNode* head,ListNode* tail)
    {
        if(head==tail)
            return NULL;
        ListNode* mid=middleNode(head,tail);
        TreeNode* root=new TreeNode(mid->val);
        root->left=buildBST(head,mid);
        root->right=buildBST(mid->next,tail);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head,NULL);
    }
};