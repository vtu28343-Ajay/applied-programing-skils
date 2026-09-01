class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // Stores indices of '('
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // Found a matching '('
                } else {
                    s[i] = '*'; // Mark unmatched ')' for removal
                }
            }
        }
        
        // Mark remaining unmatched '(' for removal
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        
        // Build the result string excluding marked characters
        string result = "";
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }
        
        return result;
    }
};