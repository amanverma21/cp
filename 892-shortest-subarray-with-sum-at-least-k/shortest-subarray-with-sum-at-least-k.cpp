class Solution {
public:
  int shortestSubarray(vector<int>& A, int k) {
        int n = A.size();
        int ans = n+1;
        vector<long long> vec(n);
        deque<int> verge;
        for(int i = 0 ; i < n ; i++){
            vec[i] = A[i];
            if(i) vec[i] += vec[i-1];
            if(vec[i] >= k){
                ans = min(ans,i+1);
            }
            while(!verge.empty() && vec[i] - vec[verge.front()] >= k){
                ans = min(ans,i-verge.front());
                verge.pop_front();
            }
            while(!verge.empty() && vec[verge.back()] >= vec[i]){
                verge.pop_back();
            }
            verge.push_back(i);
        }
        return (ans == n+1)?-1:ans;
    }

};