// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



bool isAdditiveSequence(string n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<isAdditiveSequence(s);
		cout<<endl;	
	}

}
// } Driver Code Ends


/*You are required to complete this function*/
int len(int x){
    int l = 0;
    while(x!=0){
        x/=10; l++;
    }
    return l;
}
bool isAdditiveSequence(string s)
{
    int st=0, n=s.length();
    for(int i=1; i<=n-2 && i<=8; i++){
        for(int j=1; j<=n-i && j<=8; j++){
            for(int k=1; k<=n-i-j && k<=8; k++){
                int first = stoi(s.substr(st,i));
                int second = stoi(s.substr(st+i,j));
                int third = stoi(s.substr(st+i+j,k));
                st = st+i+j+k;
                if(third==second+first){
                    first=second; second=third;
                    int expect = first+second;
                    while(st+len(expect)<=n && expect==stoi(s.substr(st,len(expect)))){
                        st+=len(expect);
                        int temp = expect;
                        expect += second;
                        second = temp;
                    }
                    if(st==n) return true;
                    else st=0;
                }
                else st=0;
            }
        }
    }
    return false;
}