class Solution {
public:
    static bool cmp(string a,string b){
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>res;
        for(auto i:nums) res.push_back(to_string(i));
        sort(res.begin(),res.end(),cmp);
        if(res[0] == "0") return "0";
        string ans = "";
        for(auto str:res) ans = ans + str;
        return ans;
    }
};