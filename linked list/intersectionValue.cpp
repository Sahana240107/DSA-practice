/*Given two linked lists head1 and head2, find the intersection of two linked lists. Each of the two linked lists contains distinct node values.

Note: The order of nodes in this list should be the same as the order in which those particular nodes appear in input head1 and return null if no common element is present.

Examples:

Input: LinkedList1: 9->6->4->2->3->8 , LinkedList2: 1->2->8->6
 
Output: 6->2->8
Explanation: Nodes 6, 2 and 8 are common in both of the lists and the order will be according to LinkedList1. 
*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {

        if(!head1 || !head2)
            return NULL;
        Node* dummy=new Node(0);
        Node* cur=dummy;
        Node* t2=head2;
        unordered_set<int> s;
        while(t2!=NULL)
        {
            s.insert(t2->data);
            t2=t2->next;
        }
        Node* t1=head1;
        while(t1!=NULL)
        {
            if(s.find(t1->data)!=s.end())
            {
                cur->next=new Node(t1->data);
                cur=cur->next;
            }
            t1=t1->next;
        }
        return dummy->next;
        
        
    }
};