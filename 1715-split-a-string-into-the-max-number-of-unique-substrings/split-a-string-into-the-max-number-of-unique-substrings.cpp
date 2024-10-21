class Solution {
    void unique(int i, string &s, int &ans, set<string> &st)
    {
        if(i == s.length())
        {
            ans = max(ans, (int)st.size());
            return;
        }
        for(int j=s.length() -i; j>=1; j--)
        {
            string back = s.substr(i,j);
            if(st.find(back) != st.end()) 
            continue;
            st.insert(back);
            unique(i+j, s, ans, st);
            st.erase(back);
        }
    }

public:
    int maxUniqueSplit(string s) {
        int ans = 0;
        set<string> st;
        unique(0, s, ans, st);
        return ans;
    }
};