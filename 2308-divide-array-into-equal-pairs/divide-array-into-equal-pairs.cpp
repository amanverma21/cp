class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>m;
        for(int i:nums) m[i]++;
        for(auto i:m) if(i.second%2) return false;
        return true;
    }
};