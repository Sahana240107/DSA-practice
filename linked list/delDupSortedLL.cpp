/*Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Examples:

Input: Linked List = 23->28->28->35->49->49->53->53
Output: 23 35
Explanation: 

The duplicate numbers are 28, 49 and 53 which are removed from the list.
*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node* dummy=new Node(0);
        dummy->next=head;
        Node* prev=dummy;
        Node* cur=head;
        while(cur)
        {
            if(cur->next && cur->data==cur->next->data)
            {
                int dup=cur->data;
                while(cur && cur->data==dup)
                    cur=cur->next;
                prev->next=cur;
            }
            else
            {
                prev=cur;
                cur=cur->next;
            }
        }
        return dummy->next;
    }
};