class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
    if(hand.size()%groupSize!=0) return 0;
    map<int,int> mp;
    for(auto it:hand){
        mp[it]++;
    }
    while(mp.size()){
        int p=mp.begin()->first;
        for(int i=0;i<groupSize;i++){
            if(mp[p+i]>0){
                mp[p+i]--;
                if(mp[p+i]==0){
                    mp.erase(p+i);
                }
            } else{
                return 0;
            }
        }
    }
    return 1;
    }
};