class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string ans="";
        sort(arr.begin(),arr.end());
        int n = arr.size();
        string first = arr[0],last = arr[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
    }
};