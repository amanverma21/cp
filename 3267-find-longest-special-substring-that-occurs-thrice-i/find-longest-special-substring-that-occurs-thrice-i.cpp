class Solution {
public:
    bool solve(string& str, int target){
        int cnt = 0;
        vector<int> vis(26, 0);
        char ch = '.';
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ch){
                cnt++;
            }else{
                cnt = 1;
                ch = str[i];
            }
            if(cnt >= target && ++vis[str[i]-'a'] == 3){
                return true;
            }
        }
        return false;
    }
    int maximumLength(string s) {
        int low = 0;
        int high = s.size()-1;
        while(low < high){
            int mid = (low + high)/2;
            if(solve(s, mid)){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low-1;
    }
};