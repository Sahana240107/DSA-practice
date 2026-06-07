/*# **Length of Loop in Linked List**

**Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list. If there's no loop present, return 0.***/

class Solution {
public:
    // Function to return the length of loop using Floyd's Algorithm
    int lengthOfLoop(Node* head) {
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                Node* temp=slow;
                int length=1;
                while(temp->next!=slow)
                {
                    temp=temp->next;
                    length++;
                }
                return length;
            }
        }
        return 0;
    }
}