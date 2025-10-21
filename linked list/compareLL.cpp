/*Given two strings, head1 and head2, represented as linked lists where each character is stored in a node's data field, complete the function compare() that mimics the behavior of strcmp(). Specifically, the function should return:

0 if both strings are identical,
1 if the first linked list is lexicographically greater, and
-1 if the second linked list is lexicographically greater.
Examples:

Input: head1 = a->b->a->b->a , head2 = a->b->a->a

Output: 1
Explanation: String consisting of nodes of first linked list is lexicographically greater than the second one. So, the result is 1.
*/
class Solution {
  public:
    int compare(Node *head1, Node *head2) {
        // Code Here
        Node* t1=head1;
        Node* t2=head2;
        bool flag=true;
        while(t1 && t2)
        {
            if(t1->data >t2->data)
                return 1;
            else if(t1->data < t2->data)
                return -1;
            t1=t1->next;
            t2=t2->next;
        }
        if(!t1 && !t2)
            return 0;
        if(!t1)
            return -1;
        else
            return 1;
    }
};