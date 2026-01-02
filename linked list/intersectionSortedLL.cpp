/*Given that two linked lists are sorted in increasing order, create a new linked list representing the intersection of the two linked lists. The new linked list should be made without changing the original lists.

Note: The elements of the linked list are not necessarily distinct.

Examples:

Input: LinkedList1 = 1->2->3->4->6, LinkedList2 = 2->4->6->8
Output: 2->4->6
Explanation: For the given two linked list, 2, 4 and 6 are the elements in the intersection.

*/
class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        if(!head1 || !head2)
            return  NULL;
        Node* t1=head1;
        Node* t2=head2;
        Node* dummy=new Node(0);
        Node* cur=dummy;
        while(t1 && t2)
        {
            if(t1->data==t2->data)
            {
                cur->next=new Node(t1->data);
                cur=cur->next;
                t1=t1->next;
                t2=t2->next;
            }
            else if(t1->data<t2->data)
                t1=t1->next;
            else
                t2=t2->next;
        }
        return dummy->next;
    }
};