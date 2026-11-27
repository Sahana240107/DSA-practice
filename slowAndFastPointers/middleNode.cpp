/*Given the head of a singly linked list, return the **middle node**.

- If there are **two middle nodes** (even length), return the **second one**.*/
class Solution {
  public:
    Node* middleNode(Node* head) {
        if (head == NULL || head->next == NULL)
            return head;

        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // middle node
    }
};

