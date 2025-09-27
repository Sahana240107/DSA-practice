/*You are given the head of a linked list, You have to return the value of the middle node of the linked list.

If the number of nodes is odd, return the middle node value.
If the number of nodes is even, there are two middle nodes, so return the second middle node value.
*/
int getMiddle(Node* head) {
        if(head==NULL || head->next==NULL)
            return head->data;
        Node* middle=head;
        Node* temp=head;
        int i=0;
        while(temp->next!=NULL)
        {
            if(i%2==0)
                middle= ->next;
            temp=temp->next;
            i++;
        }
        return middle->data;
}