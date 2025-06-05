class Solution {
public:
     vector<int> parent,rank;
    int findpar(int node){
        if(node==parent[node]) return node;

        return findpar(parent[node]);
    }
    void uni(int u,int v){
        u=findpar(u);
        v=findpar(v);
        if(u==v) return;
        if(u<v){
            parent[v]=u;
        }
        else{
            parent[u]=v;
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string basestr) {
        parent.resize(26,0);
        rank.resize(26,0);
        for(int i=0;i<26;i++) parent[i]=i;
        for(int i=0;i<s1.size();i++){
            int a=s1[i]-'a';
            int b=s2[i]-'a';
            uni(a,b);
        }
        for(int i=0;i<basestr.size();i++){
            int a=findpar(basestr[i]-'a');
            basestr[i]=a+'a';
        }
        return basestr;
    }
};