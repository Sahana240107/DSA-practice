/*You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.*/
class Solution {
  public:
  Node* reverseList(Node* head)
  {
      Node* temp=head;
      Node* prev=NULL;
      while(temp!=NULL)
      {
          Node* front=temp->next;
          temp->next=prev;
          prev=temp;
          temp=front;
      }
      return prev;
  }
    Node* addOne(Node* head) {
        Node* revHead=reverseList(head);
        Node* temp=revHead;
        int carry=1;
        while(temp!=NULL || carry)
        {
            int sum=temp->data+carry;
            temp->data=sum%10;
            carry=sum/10;
            if(!carry)
                break;
            if(temp->next==NULL && carry)
            {
                temp->next=new Node(carry);
                carry=0;
                break;
            }
            temp=temp->next;
        }
        return reverseList(revHead);
    }
};