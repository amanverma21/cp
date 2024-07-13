class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<vector<int>> v;
        for(int i=0; i<n; i++) {
            int d = directions[i] == 'R' ? 1 : 0;
            v.push_back({positions[i], healths[i], d, i});
        }
        sort(v.begin(), v.end());
        
        stack<vector<int>> s;
        
        for(auto i : v) {
            if(!s.size()) s.push(i);
            else {
                if((s.top()[2] == 0 && i[2] == 0) || (s.top()[2] == 0 && i[2] == 1) || (s.top()[2] == 1 && i[2] == 1)) {
                    s.push(i);
                    continue;
                }
                int cnt = 0, f = 0;
                while(s.size() && s.top()[2] == 1 && i[2] == 0 && s.top()[1] <= i[1] - cnt) {
                    if(s.top()[1] == i[1] - cnt) {
                        s.pop();
                        f = 1;
                        break;
                    }
                    s.pop(), cnt++;
                }
                if(!f) {
                    if(s.size() && s.top()[1] > i[1] - cnt && (s.top()[2] == 1 && i[2] == 0)) {
                        auto t = s.top(); s.pop();
                        s.push({t[0], t[1] - 1, t[2], t[3]});
                    }
                    else s.push({i[0], i[1] - cnt, i[2], i[3]});
                }
            }
        }
        vector<int> a(n), ans;
        while(s.size()) {
            auto t = s.top(); s.pop();
            a[t[3]] = t[1];
        }
        for(int i : a) {
            if(i) ans.push_back(i);
        }
        return ans;
    }
};