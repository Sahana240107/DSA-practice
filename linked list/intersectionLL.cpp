/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

*/

//SET APPROACH TIME:O(N+M) SPACE:O(N)
node* intersection(node* h1,node* h2)
{
    if(!h1 || !h2)
        return NULL;
    unordered_set<node*> s;
    node* t1=h1;
    while(t1!=NULL)
    {
        s.insert(t1);
        t1=t1->next;
    }
    node* t2=h2;
    while(t2!=NULL)
    {
        if(s.find(t2)!=s.end())
            return t2;
        t2=t2->next;
    }
    return NULL;
}

//difference approach

intgetLength(ListNode* head) {
int len =0;
while(head) {
        len++;
        head = head->next;
    }
return len;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
int lenA =getLength(headA);
int lenB =getLength(headB);

int diff =abs(lenA - lenB);

// Move longer list ahead
if(lenA > lenB) {
while(diff--) headA = headA->next;
    }else {
while(diff--) headB = headB->next;
    }

// Traverse together
while(headA && headB) {
if(headA == headB)
return headA;
        headA = headA->next;
        headB = headB->next;
    }

returnNULL;
}



//optimal approach time:O(N+M)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2) {
            t1 = (t1 == NULL) ? headB : t1->next;
            t2 = (t2 == NULL) ? headA : t2->next;
        }

        return t1; // intersection node or NULL
    }
};
