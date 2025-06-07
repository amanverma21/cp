class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        priority_queue< pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>> > pq;
        for(int i = 0;i<n;i++){
            if(s[i]=='*'){
                if(!pq.empty()){
                    pq.pop();
                }
                continue;
            }
            else{
                pq.push({s[i],-i});
            }
        }
        string res;
        vector<pair<int, char>> vp;
        while(!pq.empty()){
            vp.push_back({-pq.top().second, pq.top().first});
            pq.pop();
        }
        sort(vp.begin(), vp.end());
        for(auto it: vp){
            res+=it.second;
        }
        return res;
    }
};