/*Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

Examples :

Input: LinkedList: 1->2->3->4->5->6
 
Output: 1->3->5

Explanation: Deleting alternate nodes ie 2, 4, 6 results in the linked list with elements 1->3->5.
*/
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        Node* temp=head;  
        while(temp!=NULL&& temp->next!=NULL)
        {
            Node* toDelete=temp->next;
            temp->next=toDelete->next;
            delete toDelete;
            temp=temp->next;
        }
    }
};