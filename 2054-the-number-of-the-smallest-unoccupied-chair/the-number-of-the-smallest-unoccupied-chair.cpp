class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int reqTime = times[targetFriend][0];
        sort(times.begin(),times.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> res;
        priority_queue<int,vector<int>,greater<int>> ans;
        for(int i=0; i<times.size(); i++){
            ans.push(i);
        }
        for(int i=0; i<times.size() ; i++){
            while(!res.empty() && res.top().first <= times[i][0]){
                ans.push(res.top().second);
                res.pop();
            }
            int availableChair = ans.top();
            ans.pop();

            if(times[i][0] == reqTime) return availableChair;
            res.push({times[i][1],availableChair});
        }
        
        return -1; 
    }
};