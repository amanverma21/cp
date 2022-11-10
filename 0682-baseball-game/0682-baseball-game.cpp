class Solution {
public:
    int calPoints(vector<string>& op) {
        int x1,x2,ans=0;
        stack<int>st;
        for(string i:op){
            if(i=="C")
                st.pop();
            else if(i=="D")
                st.push(st.top()*2);
            else if(i=="+"){
                x1=st.top();
                st.pop();
                x2=st.top();
                st.push(x1);
                st.push(x1+x2);
            }
                else{
                    st.push(stoi(i));
                }
            
        }
        while(st.size()!=0){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};