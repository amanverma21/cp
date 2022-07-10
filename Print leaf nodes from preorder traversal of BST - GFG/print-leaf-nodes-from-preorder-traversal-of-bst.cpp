// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    struct TreeNode{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };

 //find leaf nodes;
 void trav(struct TreeNode *root,vector<int>&an)
 {
     if(!root)return ;
     
     if(!root->left&&!root->right)
       an.push_back(root->val);
     
     trav(root->left,an);
     trav(root->right,an);
 }
   //cunstruct tree from preeoder
 
  TreeNode* fun(int &i,int l,int pre[],int b)
    {
        if(i>=l ||pre[i]>b)return NULL;
        struct TreeNode *root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        root->val=pre[i++];
        
        root->left=fun(i,l,pre,root->val);
        root->right=fun(i,l,pre,b);
        return root;
    }
    
   vector<int> leafNodes(int pre[],int N) {
         vector<int>an;
         
        int l=  N;
       int i=0,b=INT_MAX;
       
     struct TreeNode  *root= fun(i,l,pre,b);
     
     trav(root,an);
     return an;
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends