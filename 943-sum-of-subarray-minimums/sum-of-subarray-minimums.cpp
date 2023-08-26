class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        //NAIVE APPROACH
        // // stack<int>st;
        // // vector<int>ans;
        // int sum=0;
        // for(int i=0;i<arr.size();i++){
        //     int minVal=arr[i];
        //     for(int j=i;j<arr.size();j++){
        //         minVal=min(minVal,arr[j]);
        //         sum=(sum+minVal) % mod;
        //     }
        // }
        // return sum;

        //EFFICIENT Aproach
        int n = arr.size();
        stack<int> st;
        vector<int> prevsmall(n,-1);  
        st.push(0);
        for(int i = 1; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){  
                st.pop();
            }
            if(!st.empty()) prevsmall[i]=st.top();
             st.push(i);
        }
        int m = 1e9+7;
        vector<int> ans(n,0);
        for(int i = 0; i<n; i++){
            if(prevsmall[i] == -1) ans[i] = ((i+1)*arr[i])%m;
            else ans[i]=(ans[prevsmall[i]]+(arr[i]*(i-prevsmall[i]))%m)%m;
        }
        int sum=0;
        for(auto x:ans) sum=(sum+x)%m;
        return sum;
    }
};