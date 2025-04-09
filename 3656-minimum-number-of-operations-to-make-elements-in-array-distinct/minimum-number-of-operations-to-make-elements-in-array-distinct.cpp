class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(101, 0);
        for(int i=0; i<n; i++) freq[nums[i]]++;

        int ops=0;
        for(int i=0; i<n; i+=3){
            bool flag = false;
            for(int j=0; j<3; j++){
                if(i+j >= n) break; 
                freq[nums[i+j]]--;
                if(freq[nums[i+j]] >= 1) flag = true;
            }
            if(flag) ops=(i/3)+1;
        }
        return ops;
    }
};