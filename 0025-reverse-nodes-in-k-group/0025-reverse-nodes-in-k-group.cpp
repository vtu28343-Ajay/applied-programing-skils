class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* prevGroup = &dummy;

        while (true) {
            // Check if there are at least k nodes remaining
            ListNode* kth = getKthNode(prevGroup, k);
            if (!kth) break;

            ListNode* nextGroup = kth->next;
            ListNode* curr = prevGroup->next;
            ListNode* prev = nextGroup; // Point end of reversed segment to next group

            // Reverse the k nodes
            while (curr != nextGroup) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // Connect the previous group to the newly reversed group head
            ListNode* tmp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = tmp;
        }

        return dummy.next;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr != nullptr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};