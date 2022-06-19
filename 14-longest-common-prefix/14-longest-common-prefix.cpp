class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minWordsize=INT_MAX;
        for(int i=0;i<strs.size();i++){
            int wordSize = strs[i].size();
            minWordsize = min(minWordsize, wordSize);
        }
        string ans = "";    
        for(int i=0;i<minWordsize;i++){
            for(int j=0;j<strs.size()-1;j++){
                if(strs[j][i]!=strs[j+1][i])
                return ans;
            }
        ans+=strs[0][i];
        }
        return ans;
        
    }
};