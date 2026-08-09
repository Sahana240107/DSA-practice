/*Sort a linked list of 0s, 1s and 2s
Solved
Difficulty: MediumAccuracy: 60.75%Submissions: 304K+Points: 4Average Time: 30m
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2
   
Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:
   
Input: head = 2 → 2 → 0 → 1
   
Output: 0 → 1 → 2 → 2
Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be:
   
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead=new Node(-1);
        Node* oneHead=new Node(-1);
        Node* twoHead=new Node(-1);
        Node* zero=zeroHead;
        Node* one=oneHead;
        ode* two=twoHead;
        Node* temp=head;
        while(temp)
        {
            if(temp->data==0)
            {
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1)
            {
                one->next=temp;
                one=one->next;
            }
            else
            {
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        zero->next=oneHead->next?oneHead->next:twoHead->next;
        one->next=twoHead->next;
        two->next=NULL;
        return zeroHead->next;
    }
};