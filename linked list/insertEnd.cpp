/*You are given the head of a Singly Linked List and a value x, insert that value x at the end of the LinkedList 
and return the head of the modified Linked List.

Examples :

Input: x = 6,
   
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Explanation: We can see that 6 is inserted at the end of the linkedlist.
   */
   class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node *newNode=new Node(x);
        if(head==NULL)
         return newNode;
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        return head;
    }
};