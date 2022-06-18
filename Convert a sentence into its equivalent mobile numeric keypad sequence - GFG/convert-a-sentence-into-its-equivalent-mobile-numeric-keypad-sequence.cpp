// { Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string printSequence(string S)
{
    //code here.
    string ans="";
   for(int i=0;i<S.size();i++)
   {
       if(S[i]<'A'||S[i]>'Z')
       {
           ans+='0';
           continue;
       }
       int x=S[i]-'A';
       if(x<18||(x>18&&x<=20)||(x>=22&&x<24))
       {
           int t=(x/3)+2;
           if(x<18){
           string ts=to_string(t);
           for(int i=0;i<=(x%3);i++)
           ans+=ts;}
           else if(x>18&&x<24)
           {
               string ts=to_string(t);
           for(int i=0;i<=(x%3)-1;i++)
           ans+=ts; 
           }
       }
       else if(x==18||x==21||(x>=24)){
           int t=(x/3)+1;
           if(x==18)
           {
                string ts=to_string(t);
           for(int i=0;i<=3;i++)
           ans+=ts;
           }
           else if(x==21){
                string ts=to_string(t);
           for(int i=0;i<=2;i++)
           ans+=ts;
           }
           else if(x==24){
                string ts=to_string(t);
           for(int i=0;i<=2;i++)
           ans+=ts;
           }
           else if(x==25){
                string ts=to_string(t);
           for(int i=0;i<=3;i++)
           ans+=ts;
           }
       }
   }
   return ans;
}