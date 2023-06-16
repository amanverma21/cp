int M = 1e9 + 7;
vector<vector<long long>> comb(1001);
class Solution {
public:
int helper(vector<int> nums)
{
    if(nums.size() <= 1)
        return 1;
    
    vector<int> left, right;
    for(int a = 1; a < nums.size(); a++)
    {
        if(nums[0] > nums[a])
            left.push_back(nums[a]);
        else
            right.push_back(nums[a]);
    }
    
    long long ans_left = helper(left), ans_right = helper(right);
    return (((ans_left * ans_right) % M) * comb[nums.size() - 1][left.size()]) % M;
}
    int numOfWays(vector<int>& nums) {
         if(comb[0].empty())
        for(int i = 0; i <= 1000; i++)
        {
            comb[i].resize(i + 1, 1);
            for(int j = 1; j < i; j++)
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
        }
    
    return helper(nums) - 1;
    }
};