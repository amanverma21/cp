class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        for(int i = 0 ; i< s.length() ; i++){
            char c = s[s.length() -1];
            s = s.substr(0 , s.length() -1);
            s = c + s;
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};