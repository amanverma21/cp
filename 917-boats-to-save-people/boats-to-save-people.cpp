class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    int ans=0;
    sort(people.begin(),people.end());
    for(int i=0,j=people.size()-1;i<=j;--j,++ans){
        if(people[i]+people[j]<=limit) i++;
    }
    return ans;
    }
};