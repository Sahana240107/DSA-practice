/*You are given a node del_node of a Singly Linked List where you have to delete this given node from the linked list but you are not given the head of the list.

After deleting the given node:

The number of nodes in the linked list should decrease by one.
All the values before & after the del_node node should be in the same order.
Note: It is guaranteed that there exists a node with a value equal to the del_node value and it will not be the last node of the linked list.

Examples:

Input: Linked List = 1 -> 2, del_node = 1
Output: 2
Explanation: After deleting 1 from the linked list, we have remaining nodes as 2.
*/
class Solution {
  public:
    void deleteNode(Node* del_node) {
        // code here
        Node* nextNode=del_node->next;
        del_node->data=nextNode->data;
        del_node->next=nextNode->next;
        
    }
};