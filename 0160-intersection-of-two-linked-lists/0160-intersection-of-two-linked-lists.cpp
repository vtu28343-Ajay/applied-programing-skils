class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
        // Traverse both lists. When a pointer reaches the end, redirect it to the other list's head.
        // If they intersect, they will meet at the intersection node after traversing (lenA + lenB) nodes.
        // If they don't intersect, both will eventually become nullptr at the same time.
        while (ptrA != ptrB) {
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        
        return ptrA;
    }
};