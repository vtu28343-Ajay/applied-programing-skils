class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque; // Decreasing order to keep track of maximums
        deque<int> minDeque; // Increasing order to keep track of minimums
        
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            // Maintain maxDeque in decreasing order
            while (!maxDeque.empty() && maxDeque.back() < nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(nums[right]);
            
            // Maintain minDeque in increasing order
            while (!minDeque.empty() && minDeque.back() > nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(nums[right]);
            
            // If absolute difference exceeds limit, shrink window from left
            while (maxDeque.front() - minDeque.front() > limit) {
                if (maxDeque.front() == nums[left]) {
                    maxDeque.pop_front();
                }
                if (minDeque.front() == nums[left]) {
                    minDeque.pop_front();
                }
                ++left;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};