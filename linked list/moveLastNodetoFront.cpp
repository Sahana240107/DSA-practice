/*You are given the head of a Linked List. You have to move the last element to the front of the Linked List and return the head the modified linked list.
*/
Node *moveToFront(Node *head) {
        if(head==NULL || head->next==NULL)
        return head;
        Node* prev=NULL;
        Node* temp=head;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        temp->next=head;
        head=temp;
        return head;
    }