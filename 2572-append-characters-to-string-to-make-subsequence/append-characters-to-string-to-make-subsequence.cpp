class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = t.length();
        int tPointer = 0;
        for (int sPointer = 0; sPointer < s.length(); sPointer++) {
            if (tPointer < n && s[sPointer] == t[tPointer]) {
                tPointer++;
            }
        }
        return n - tPointer;
    }
};