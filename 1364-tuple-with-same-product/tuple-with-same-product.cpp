
class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        unordered_map<int, int> map;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int product = nums[i] * nums[j];
                count += (map[product] * 8);
                map[product]++;
            }
        }
        return count;
    }
};