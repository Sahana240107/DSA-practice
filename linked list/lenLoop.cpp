/*Given the head of a linked list, determine whether the list contains a loop.
 If a loop is present, return the number of nodes in the loop, otherwise return 0.
*/
class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                break;
        }
        if(fast==NULL || fast->next==NULL)
            return 0;
        int n=1;
        Node* temp=slow->next;
        while(temp!=slow)
        {
            n++;
            temp=temp->next;
        }
        return n;
        
    }
};