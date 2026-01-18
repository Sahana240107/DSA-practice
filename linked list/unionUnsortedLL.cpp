/*Given two linked lists (L1 & L2), your task is to complete the function makeUnion(), which returns the union list of two linked lists. This union list should include all the distinct elements only and it should be sorted in ascending order.

Examples:

Input: L1 = 9->6->4->2->3->8, L2 = 1->2->8->6->2
Output: 1 -> 2 -> 3 -> 4 -> 6 -> 8 -> 9

Explanation: All the distinct numbers from two lists, when sorted form the list in the output. 
*/

class Solution {
  public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2) {
        // code here
        set<int> st;
        Node* t1=head1;
        Node* t2=head2;
        while(t1)
        {
            st.insert(t1->data);
            t1=t1->next;
        }
        while(t2)
        {
            st.insert(t2->data);
            t2=t2->next;
        }
        Node* dummy=new Node(0);
        Node* cur=dummy;
        for(int it:st)
        {
            cur->next=new Node(it);
            cur=cur->next;
        }
        return dummy->next;
        
    }
};