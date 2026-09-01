class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<int> st; // Stores indices

        for (int i = 0; i < prices.size(); i++) {
            // Apply discount to all previous items where current price is <= item price
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};