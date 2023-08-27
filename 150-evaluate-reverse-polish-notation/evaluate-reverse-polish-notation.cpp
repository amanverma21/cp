class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b+a;
                st.push(c);
            }
           else if(tokens[i]=="-"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b-a;
                st.push(c);
            }
           else if(tokens[i]=="/"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b/a;
                st.push(c);
            }
            else if(tokens[i]=="*"){
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int c=b*a;
                st.push(c);
            }
            else{
            int x=stoi(tokens[i]);
            st.push(x);
            }
        }
        return st.top();
    }
};