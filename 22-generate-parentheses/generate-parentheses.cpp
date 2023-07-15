class Solution {
public:
	vector<string>ans;
	void solve(string& s,int close,int open){
		if(!open && !close){
			ans.push_back(s);
			return;
		}
		if(open>0){
			s.push_back('(');
			solve(s,close,open-1);
			s.pop_back();
		}    
		if(close>0 && open<close){
			s.push_back(')');
			solve(s,close-1,open);
			s.pop_back();
		}    
	}

	vector<string> generateParenthesis(int n) {
		string s="";
		solve(s,n,n);
		return ans;
	}
};