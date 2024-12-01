class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<float, bool> mp;
        for (float i: arr) {
            if (mp.find(i*2) != mp.end() || mp.find(i/2) != mp.end()) {
                return true;
            } else {
                mp[i] = true;
            }
        }
        return false;
    }
};