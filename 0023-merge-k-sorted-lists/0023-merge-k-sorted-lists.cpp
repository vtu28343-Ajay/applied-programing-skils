class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for min-heap
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        // Push the head of each non-empty list into the heap
        for (ListNode* listHead : lists) {
            if (listHead != nullptr) {
                minHeap.push(listHead);
            }
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Extract the smallest node and push its next node
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            
            tail->next = smallest;
            tail = tail->next;
            
            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }
        
        return dummy.next;
    }
};