/*86. Partition List

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode less(0);
        ListNode greater(0);
        ListNode* t1=&less;
        ListNode* t2=&greater;
        ListNode* cur=head;
        while(cur)
        {
            if(cur->val<x)
            {
                t1->next=cur;
                t1=t1->next;
            }
            else
            {
                t2->next=cur;
                t2=t2->next;
            }
            cur=cur->next;
        }
        t2->next=NULL;
        t1->next=greater.next;
        return less.next;
    }
};