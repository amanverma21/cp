class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) arr[i]-=i; 
        int sum=0,ans=0; 
        for(int i=0;i<arr.size();i++){
            sum+= arr[i];
            if(sum==0) ans++; 
        }
        return ans;
    }
};