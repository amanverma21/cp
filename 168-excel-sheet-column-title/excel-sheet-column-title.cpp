class Solution {
public:
    string convertToTitle(int col) {
        string ans;
        while(col){
            col--;
            char ch = 'A' + col % 26;
            ans = ch + ans;
            col /= 26;
        }
        return ans;
    }
};