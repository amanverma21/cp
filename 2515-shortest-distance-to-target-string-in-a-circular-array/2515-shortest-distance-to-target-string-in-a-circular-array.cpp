class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int cnt=INT_MAX;
        int n=words.size();
        for(int i=0;i<words.size();i++){
            if(words[i]==target)
            {
                int ans=min(abs(startIndex-i),n-abs(startIndex-i));
                cnt=min(cnt,ans);
            }
        }
        if(cnt==INT_MAX) return -1;
        return cnt;
    }
};