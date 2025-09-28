/*You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. You have to return the head of the linked list representing the sum of these two numbers.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

*/
class Solution {
  public:
    Node* reverse(Node *head)
    {
        Node* temp=head;
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
    Node* removeZeros(Node* head)
    {
        while(head!=NULL && head->data==0)
        {
            head=head->next;
        }
        if(head==NULL)
            return new Node(0);
        return head;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        head1=reverse(head1);
        head2=reverse(head2);
        Node dummy(0);
        Node *current=&dummy;
        int sum=0,carry=0;
        while(head1!=NULL || head2!=NULL || carry!=0)
        {
            sum=0;
            if(head1!=NULL)
            {
                sum+=head1->data;
                head1=head1->next;
            }
            if(head2!=NULL)
            {
                sum+=head2->data;
                head2=head2->next;
            }
            sum+=carry;
            carry=sum/10;
            current->next=new Node(sum%10);
            current=current->next;
        }
        dummy.next=reverse(dummy.next);
        dummy.next=removeZeros(dummy.next);
        return dummy.next;
        
    }
};