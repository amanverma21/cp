class Solution {
public:
    int possibleStringCount(string word) {
        int result = 1;
        int prev = 0;
        int next = 1;
        while (next < word.size()) {
            if (word[next] == word[prev]) {
                next++;
            } else {
                result += (next - prev - 1);
                prev = next;
                next++;
            }
        }
        result += (next - prev - 1);
        return result;
    }
};