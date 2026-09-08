class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq; // Stores indices of array elements
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are out of the current window boundary
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Maintain monotonic decreasing order: remove smaller elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Append max for current window once first window size k is reached
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};