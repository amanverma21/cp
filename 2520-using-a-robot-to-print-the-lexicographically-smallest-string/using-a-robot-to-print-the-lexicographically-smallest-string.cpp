class Solution {
public:
    string robotWithString(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string result = "";
        stack<char> t;
        char min_char = 'a';
        for (char c : s) {
            t.push(c);
            count[c - 'a']--;
            while (min_char <= 'z' && count[min_char - 'a'] == 0) {
                min_char++;
            }
            while (!t.empty() && t.top() <= min_char) {
                result += t.top();
                t.pop();
            }
        }
        
        return result;
    }
};