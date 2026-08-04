#include <vector>
#include <numeric>

class Solution {
public:
    std::vector<int> getSumAbsoluteDifferences(std::vector<int>& nums) {
        int n = nums.size();
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        std::vector<int> result(n);
        int leftSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int rightSum = totalSum - leftSum - nums[i];
            
            int leftCount = i;
            int rightCount = n - 1 - i;
            
            int leftDiff = leftCount * nums[i] - leftSum;
            int rightDiff = rightSum - rightCount * nums[i];
            
            result[i] = leftDiff + rightDiff;
            leftSum += nums[i];
        }
        
        return result;
    }
};