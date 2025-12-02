/*Given the head of a singly linked list, you have to find whether the given linked list is sorted or not.
Note: The sorting can either be non-increasing or non-decreasing.

Examples:

Input: head: 5 -> 5 -> 6 -> 7 -> 8
Output: true
*/
class Solution {
  public:
    bool isSorted(Node* head) {
        // code here
        int isAscend=1;
        if(head==NULL || head->next==NULL)
        {
            return true;
        }
        Node* second=head->next;
        if(head->data>second->data)
        {
            isAscend=0;
        }
        if(head->data==second->data)
        {
                Node* third=second->next;
                if(second->data>third->data)
                    isAscend=0;
        }
        Node* prev=head;
        Node* temp=head->next;
        while(temp!=NULL)
        {
            if(isAscend && prev->data>temp->data)
                return false;
            else if(!isAscend && prev->data<temp->data)
                return false;
            prev=temp;
            temp=temp->next;
        }
        return true;
    }
};