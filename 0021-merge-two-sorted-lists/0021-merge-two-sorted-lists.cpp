class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node acts as a placeholder for the start of the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Traverse both lists and append the smaller value to tail
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining nodes of whichever list is non-empty
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        return dummy.next;
    }
};