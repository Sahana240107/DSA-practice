/*Given a linked list, you have to perform the following task:

Extract the alternative nodes starting from the second node.
Reverse the extracted list.
Append the extracted list at the end of the original list.
Note: Try to solve the problem without using any extra memory.

Examples:

Input: LinkedList: 10->4->9->1->3->5->9->4
Output: 10->9->3->9->4->5->1->4

Explanation: Alternative nodes in the given linked list are 4,1,5,4.
 Reversing the alternative nodes from the given list, and then appending 
 them to the end of the list results in a list 10->9->3->9->4->5->1->4.*/
 class Solution {
  public:
    void rearrange(Node* head) {
        // add code here
        if(!head||!head->next)
            return;
        Node* last=head;
        while(last->next)
            last=last->next;//find last node
        int i=1;
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=last)
        {
            if(i%2==0)//even node moved to last nodes next
            {

                Node* front=temp->next;
                temp->next=last->next;
                prev->next=front;
                last->next=temp;
                prev=temp;
                temp=front;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
            i++;
        }
    }
};

//clear alternate solution
class Solution {
  public:
    void rearrange(Node* head) {
        if (!head || !head->next) return;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        // Step 1: Separate odd and even nodes
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = NULL;

        // Step 2: Reverse the even list
        Node* prev = NULL;
        Node* curr = evenHead;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Append reversed even list to odd list
        odd = head;
        while (odd->next) odd = odd->next;
        odd->next = prev;
    }
};
