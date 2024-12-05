class Solution {
public:

    bool solve(string s1,string s2){
        string a,b;
        for(auto it : s1) if(it!='_') a+=it;
        for(auto it : s2) if(it!='_') b+=it;
        return a==b;
    }

    bool canChange(string start, string target) {
        int n = start.length();
        vector<int> ls,le,rs,re;

        if(!solve(start,target)) return false;
        for(int i=0 ; i<=n ; i++){
            if(start[i]=='L') ls.push_back(i);
            if(start[i]=='R') rs.push_back(i);
            if(target[i]=='L') le.push_back(i);
            if(target[i]=='R') re.push_back(i);
        }
        
        for(int i=0 ; i<ls.size() ; i++) 
            if(ls[i]<le[i]) return false;
        for(int i=0 ; i<rs.size() ; i++) 
            if(rs[i]>re[i]) return false;
        return true;
    }
};