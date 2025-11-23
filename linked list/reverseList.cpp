/*You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list.*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node *temp=head;
        Node *prev=NULL;
        while(temp!=NULL)
        {
            Node *front=temp->next;//store next element
            temp->next=prev;//next pointer of temp points to previous element
            prev=temp;//move prev
            temp=front;//move temp
        }
        return prev;
    }
};