class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int len = pref.length();
        for(string word: words){
            bool flag = false;
            for(int i =0; i<len; i++){
                if(word[i]!=pref[i]){
                    flag = true;
                    break;
                }
            }
            if(flag==false){
                count++;
            }
        }
        return count;
    }
};