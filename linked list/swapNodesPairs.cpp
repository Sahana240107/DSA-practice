/*Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:

*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        while(prev->next && prev->next->next)
        {
            ListNode* first=prev->next;
            ListNode* second=first->next;
            first->next=second->next;
            second->next=first;
            prev->next=second;
            prev=first;
        }
        return dummy.next;
    }
};


//RECURSIVE
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode* first=head;
        ListNode* second=head->next;
        first->next=swapPairs(second->next);
        second->next=first;
        return second;
    }
};