class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1)
            return word;

        string ans = "";
        int len = n - numFriends + 1;

        for (int i = 0; i < n; i++) {
            string str;
            bool check = false;
            for (int j = i; j < min(len+i, n); j++) {
                str.push_back(word[j]);
               
                if(str.size()>ans.size() || str.back() > ans[str.size() -1] ){
                      ans = str;
                      check = true;
                }
                if(str.back() < ans[str.size()-1]){
                      break;
                }
            }
        }
        return ans;
    }
};