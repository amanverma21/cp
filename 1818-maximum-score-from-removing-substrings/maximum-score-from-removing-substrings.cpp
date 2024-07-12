class Solution {
public:
    int maximumGain(string str, int x, int y) {
        int ans = 0;
        stack<char> s;
        if (x < y) {
            for (char i : str) {
                if (!s.empty() && s.top() == 'b' && i == 'a') {
                    s.pop();
                    ans += y;
                } else {
                    s.push(i);
                }
            }
            string remaining;
            while (!s.empty()) {
                remaining += s.top();
                s.pop();
            }
            reverse(remaining.begin(), remaining.end());
            for (char ch : remaining) {
                if (!s.empty() && s.top() == 'a' && ch == 'b') {
                    s.pop();
                    ans += x;
                } else {
                    s.push(ch);
                }
            }
        } else {
            for (char i : str) {
                if (!s.empty() && s.top() == 'a' && i == 'b') {
                    s.pop();
                    ans += x;
                } else {
                    s.push(i);
                }
            }

            string remaining;
            while (!s.empty()) {
                remaining += s.top();
                s.pop();
            }
            reverse(remaining.begin(), remaining.end());
            for (char ch : remaining) {
                if (!s.empty() && s.top() == 'b' && ch == 'a') {
                    s.pop();
                    ans += y;
                } else {
                    s.push(ch);
                }
            }
        }
        return ans;
    }
};