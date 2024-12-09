class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& qu) {
        vector<bool> vect;
        vector<int> sp; 
        int p = (nums[0] % 2) ? 1 : 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] % 2) {
                if (p == 0) {
                    p = 1;
                } else {
                    sp.push_back(i);
                }
            } else {
                if(p == 1){
                    p=0;
                }
                else{
                    sp.push_back(i);
            }
        }
        }
        for (auto& q : qu) {
            int start = q[0], end = q[1];
            int lb = upper_bound(sp.begin(), sp.end(), start) - sp.begin();
            if (lb >= sp.size() || sp[lb] > end) {
                vect.push_back(true);
            } else {
                vect.push_back(false);
            }
        }
        
        return vect;
    }
};