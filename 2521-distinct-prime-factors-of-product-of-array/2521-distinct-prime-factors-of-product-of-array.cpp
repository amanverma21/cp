class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            for(int j=2;j*j<=n;j++)
            {
                while(n%j==0)
                {
                    s.insert(j);
                    n/=j;
                }
            }
            if(n>1)
                s.insert(n);
            
        }
        return s.size();
    }
};