class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; // Pointer for popped array
        
        for (int val : pushed) {
            st.push(val);
            
            // Pop from stack as long as the top element matches popped[j]
            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        
        // If stack is empty, all elements were validly pushed and popped
        return st.empty();
    }
};