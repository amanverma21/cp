class Solution {
public:
    vector<int> grayCode(int n) {
        unordered_map<char,int>mp;
        vector<int>ans;
        int p=(1<<n);
        for(int i=0;i<p;i++){
            ans.push_back(i^(i/2));
        }
        return ans;
    }
};