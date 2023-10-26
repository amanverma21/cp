class Solution {
public:
    const int mod = 1e9 + 7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, long long int> mp;
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size(); i++) {
            mp.insert({ arr[i], 1 });
        }
        
        for (int i = 1; i < arr.size(); i++) {
            long long int cnt = 0;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    if (mp.find(arr[i] / arr[j]) != mp.end()) {
                        cnt += mp.find(arr[j])->second * mp.find(arr[i] / arr[j])->second;
                    }
                }
            }
            mp.find(arr[i])->second += cnt;
        }
        
        long long int ans = 0;
        for (auto it : mp) {
            ans += it.second;
        }
        
        return ans % mod;
    }
};
