class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        // Traverse nums2 to find the next greater element for each value
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Map the results back to nums1
        vector<int> ans;
        ans.reserve(nums1.size());
        for (int num : nums1) {
            if (nextGreater.count(num)) {
                ans.push_back(nextGreater[num]);
            } else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};