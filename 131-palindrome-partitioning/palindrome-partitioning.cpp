class Solution {
private:
    bool isPalindrome(string& s, int l, int r)
    {
        while(l < r)
        {
            if(s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
    void solve(int idx, string& s, vector<string>& output, vector<vector<string>>& ans, int n)
    {
        if(idx == n)
        {
            ans.push_back(output);
            return;
        }
        for(int i=idx; i<n; i++)
        {
            if(isPalindrome(s, idx, i))
            {
                output.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, output, ans, n);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(0, s, output, ans, s.size());
        return ans;
    }
};