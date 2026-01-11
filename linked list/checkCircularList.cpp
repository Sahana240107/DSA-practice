/*Given the head, the head of a singly linked list, Returns true if the linked list is circular & false if it is not circular.

A linked list is called circular if it is not NULL terminated and all nodes are connected in the form of a cycle. 

Note: The linked list does not contain any inner loop.

Examples:

Input: 

Output: true
Explanation: As shown in figure the first and last node is connected, i.e. 5 --> 2*/
class Solution {
  public:
    bool isCircular(Node *head) {
        // Your code here
        if(head==NULL)
            return false;
        Node* temp=head;
        while(temp->next!=NULL && temp->next!=head)
            temp=temp->next;
        if(temp->next==head)
            return true;
        else
           return false;
    }
};