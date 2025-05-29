class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> next1(n), next2(m);
        vector<int> ret(n);
        vector<int> inDegree1(n), inDegree(m);
        vector<int> distCount;

        for(auto& edge : edges1) {
            next1[edge[0]].push_back(edge[1]);
            next1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge : edges2) {
            next2[edge[0]].push_back(edge[1]);
            next2[edge[1]].push_back(edge[0]);
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        int odd2 = 0, even2 = 0;
        vector<bool> visited(m);
        unordered_map<int, int> mp;
        while(!q.empty()) {
            auto[cur, dist] = q.front();
            q.pop();

            if(visited[cur])
                break;
            visited[cur] = true;
            if(dist % 2 != 0)
                even2++;
            else
                odd2++;
            for(auto& nxt : next2[cur])
                if(!visited[nxt])
                    q.push({nxt, dist+1});
        }

        q.push({0, 0});
        visited = vector<bool>(n);
        vector<int> odds, evens;
        int odd1 = 0, even1 = 0;
        while(!q.empty()) {
            auto[cur, dist] = q.front();
            q.pop();

            if(visited[cur])
                break;
            visited[cur] = true;
            if(dist % 2 == 0) {
                even1++;
                evens.push_back(cur);
            }
            else {
                odd1++;
                odds.push_back(cur);
            }
            for(auto& nxt : next1[cur])
                if(!visited[nxt])
                    q.push({nxt, dist+1});
        }
        
        for(auto e : evens) {
            ret[e] = even1 + max(odd2, even2);
        }
        for(auto o : odds) {
            ret[o] = odd1 + max(odd2, even2);
        }
        return ret;
    }
};