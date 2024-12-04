class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        string cyclic = "abcdefghijklmnopqrstuvwxyza";
        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            while (i < str1.size() && (cyclic[str1[i]-'a'+1] != str2[j] && str1[i] != str2[j])) i++;
            if (i == str1.size()) return false;
            
            i++;
            j++;
        }
        return (j == str2.size());
    }
};