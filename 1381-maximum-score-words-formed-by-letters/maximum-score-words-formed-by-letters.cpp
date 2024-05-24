class Solution {
public:
    bool valid(map<char,int> &mp,string &x){
        map<char,int>mp2;
        for(auto c:x){
            mp2[c]++;
        }
        for(auto c:mp2){
                if(mp[c.first]-c.second<0){
                    return false;
                }
            }
            return true;
    }
    int f(int i,vector<string>& words, map<char,int> &mp, vector<int>& score){
        if(i==words.size()){
            return 0;
        }
        int ans=f(i+1,words,mp,score);
        int ans2=0;
        if(valid(mp,words[i])){    
            for(auto c:words[i]){
                if(mp[c]-1>=0){
                    mp[c]--;
                    ans2+=score[c-'a'];
                }
            }
            ans2=ans2+f(i+1,words,mp,score);
            
            for(auto c:words[i]){
                mp[c]++;
            }
        }
        return max(ans,ans2);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char,int>mp;
        for(auto x:letters){
            mp[x]++;
        }
        return f(0,words,mp,score);
    }
};