class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long>pqueue;
        for(int i = 0 ; i < gifts.size() ; i++) pqueue.push(gifts[i]);
        long long ans = 0;
        while(k--){   
            int temp = sqrt(pqueue.top());
            pqueue.pop();
            pqueue.push(temp);
        }
        while(!pqueue.empty()){
            ans += pqueue.top();
            pqueue.pop();
        }
        return ans;
    }
};