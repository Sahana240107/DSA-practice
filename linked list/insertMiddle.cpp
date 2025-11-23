/*Given the head of a Singly Linked List and a value x. The task is to insert the key in the middle of the linked list.

Examples :

Input: LinkedList = 1->2->4 , x = 3
Output: 1->2->3->4
Explanation: 

The new element is inserted after the current middle element in the linked list.
Input: LinkedList = 10->20->40->50 , x = 30
Output: 10->20->30->40->50
Explanation: 

The new element is inserted after the current middle element in the linked list and Hence, the output is 10->20->30->40->50.*/
class Solution {
  public:
    Node *insertInMiddle(Node *head, int x) {
        // Code Here
        Node* p=new Node(x);
        if(head==NULL)
            return p;
        Node* slow=head;
        Node* fast=head->next;//for even length to stop at first middle
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        p->next=slow->next;
        slow->next=p;
        return head;
    }
};