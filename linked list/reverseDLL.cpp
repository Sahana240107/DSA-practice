/*Reverse a Doubly Linked List
Solved
Difficulty: EasyAccuracy: 70.38%Submissions: 225K+Points: 2Average Time: 15m
Given the head of a doubly linked list, reverse the list and return the head of the reversed doubly linked list.

Note: Driver code will print the returned list in both forward and backward directions.

Examples:

Input:

Output: 
5 <-> 4 <-> 3
3 <-> 4 <-> 5
Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* temp=head;
        Node* newHead=NULL;
        while(temp)
        {
            newHead=temp;
            Node* back=temp->prev;
            temp->prev=temp->next;
            temp->next=back;
            temp=temp->prev;
        }
        return newHead;
    }
};