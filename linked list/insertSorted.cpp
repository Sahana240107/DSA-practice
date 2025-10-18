/*Given a linked list sorted in ascending order and an integer called key, insert data in the linked list such that the list remains sorted.

Examples:

Input: LinkedList: 25->36->47->58->69->80, key: 19
Output: 19->25->36->47->58->69->80

Explanation: After inserting 19 the sorted linked list will look like the one in the output.
Input: LinkedList: 50->100, key: 75
Output: 50->75->100

Explanation: After inserting 75 the sorted linked list will look like the one in the output*/
class Solution {
  public:
    // Should return head of the modified linked list
    Node* sortedInsert(Node* head, int key) {
        // Code here
        Node* p=new Node(key);
        if(!head)
            return p;
        if(head->data>key)
        {
            p->next=head;
            head=p;
            return head;
        }
        Node* temp=head;
        Node* prev=NULL;
        while(temp!=NULL && temp->data<key)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=p;
        p->next=temp;
        return head;
    }
};