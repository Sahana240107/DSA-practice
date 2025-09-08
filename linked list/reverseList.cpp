/*You are given the head of a singly linked list. You have to reverse the linked list and return the head of the reversed list.*/
/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = NULL ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        // code here
        Node *temp=head;
        Node *prev=NULL;
        while(temp!=NULL)
        {
            Node *front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};