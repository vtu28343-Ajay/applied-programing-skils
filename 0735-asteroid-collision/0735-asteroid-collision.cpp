class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Use vector as a stack for easy conversion to result

        for (int a : asteroids) {
            bool exploded = false;

            // Collision only happens when stack top is moving right (positive)
            // and the current asteroid is moving left (negative)
            while (!st.empty() && st.back() > 0 && a < 0) {
                if (st.back() < -a) {
                    st.pop_back(); // Stack top asteroid explodes, continue checking
                } else if (st.back() == -a) {
                    st.pop_back(); // Both explode
                    exploded = true;
                    break;
                } else {
                    exploded = true; // Current asteroid explodes
                    break;
                }
            }

            // If current asteroid didn't explode, push it to stack
            if (!exploded) {
                st.push_back(a);
            }
        }

        return st;
    }
};