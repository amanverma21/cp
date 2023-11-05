class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int mex = *max_element(arr.begin(),arr.end());
        int n = arr.size();
        if(k>=arr.size()) return mex;
        int curr_win = arr[0];
        int curr_str = 0;
        for(int i=1;i<n;i++){
            if(curr_win>arr[i]) curr_str++;
            else{
                curr_str=1;
                curr_win=arr[i];
            }
            if(curr_str==k ) return curr_win;
        }
        return curr_win;
    }
};