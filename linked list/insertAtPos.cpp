/*You are given the head of a Singly Linked List, a position pos and value val. 
Insert the val data at the given position (1-based index) of the LinkedList and return the head of the modified Linked List.

Examples:

Input: pos = 3, val = 4,
    
Output: 1 -> 3 -> 4
Input: pos = 2, val = 5,
    
Output: 1 -> 5 -> 2 -> 9
*/
class Node
{
    int data;
    Node* next;
};
class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        Node* newNode=new Node(val);
        if(head==NULL)
            return newNode;
        if(pos==1)
        {
            newNode->next=head;
            head=newNode;
            return head;
        }
        int i=1;
        Node* temp=head;
        while(temp!=NULL && i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        return head;
    }
};