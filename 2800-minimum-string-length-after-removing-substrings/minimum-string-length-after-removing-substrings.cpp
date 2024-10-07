class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char it : s) {
            if (!st.empty() && ((it == 'B' && st.top() == 'A') || (it == 'D' && st.top() == 'C'))) {
                st.pop();
            } else {
                st.push(it);
            }
        }
        return st.size();
    }
};