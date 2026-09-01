class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        // Push to minSt if it's empty or val is smaller than/equal to current minimum
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        // If popping the minimum value, pop it from minSt as well
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */