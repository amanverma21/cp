class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n=happiness.size();
        priority_queue<int> pq(happiness.begin(), happiness.end());
        long long sum=0;
        for(int i=0; i<k; i++){
            long long x=max(0, pq.top()-i);
            pq.pop();
            sum+=x;
        }
            
        return sum;
        
    }
};