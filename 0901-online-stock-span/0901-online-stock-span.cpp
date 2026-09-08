class StockSpanner {
private:
    // Stack stores pairs of {price, calculated_span}
    stack<pair<int, int>> st;

public:
    StockSpanner() {}
    
    int next(int price) {
        int span = 1;
        
        // Pop elements with price less than or equal to current price
        // and add their spans to the current span.
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */