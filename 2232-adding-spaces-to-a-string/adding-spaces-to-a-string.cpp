class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int size = s.size();
        int spCnt = spaces.size();
        s.resize(size + spCnt, ' ');
        int pnew = size + spCnt - 1; 
        int pold = size - 1;              
        int spPnt = spCnt - 1;    

        while (pold >= 0 || spPnt >= 0) {
            if (spPnt >= 0 && pold == spaces[spPnt] - 1) {
                s[pnew--] = ' ';     
                spPnt--;      
            } else {
                if (pold >= 0) {
                    s[pnew--] = s[pold--];   
                }
            }
        }
        return s;
    }
};
