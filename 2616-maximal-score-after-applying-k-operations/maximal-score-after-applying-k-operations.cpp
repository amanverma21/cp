class Solution {
public:
#define ll long long
    long long maxKelements(vector<int>& nums, int k) {
        ll n = nums.size() , sum = 0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++) pq.push(nums[i]);
        while(k--){
            ll x = pq.top();
            sum += x;
            pq.pop();
            pq.push(ceil((double)x/(double)3));
        }
        return sum;
    }
};