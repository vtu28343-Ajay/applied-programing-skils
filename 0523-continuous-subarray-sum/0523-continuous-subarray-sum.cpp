class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Map to store the first occurrence index of prefix_sum % k
        unordered_map<int, int> remainderMap;
        
        // Base case: remainder 0 at index -1 handles subarrays starting from index 0
        remainderMap[0] = -1;
        
        int runningSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            runningSum += nums[i];
            int remainder = runningSum % k;
            
            // Handle negative remainders if array contains negative numbers
            if (remainder < 0) {
                remainder += k;
            }
            
            if (remainderMap.count(remainder)) {
                // Check if the subarray length is at least 2
                if (i - remainderMap[remainder] >= 2) {
                    return true;
                }
            } else {
                // Store only the first occurrence to maximize the subarray length
                remainderMap[remainder] = i;
            }
        }
        
        return false;
    }
};