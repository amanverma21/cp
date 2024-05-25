class Solution {
public:
    vector<string> ans;
    map<string,int>mp;

    void allWord(int st,int end,string &s,vector<string> &temp){
        if(st>s.size()){
            return;
        }
        if(st==s.size()){
            string an="";
            for(auto i:temp){
                an+=i;
                an+=' ';
            }
            an.pop_back();
            ans.push_back(an);
            return;
        }

        if(end>s.size()){
            return;
        }

        string s1=s.substr(st,end);
        if(mp[s1]>0){
            temp.push_back(s1);
            allWord(st+end,1,s,temp);
            temp.pop_back();
            allWord(st,end+1,s,temp);
        }else{
            allWord(st,end+1,s,temp);
        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto i:wordDict) mp[i]++;
        vector<string> temp;
        allWord(0,1,s,temp);
        return ans;
    }
};