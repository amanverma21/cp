//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{

    public:
    Node*findTarget(Node* root, int home, int k){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            if(temp->data==home){
                return temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    
    void Parents(Node* root, unordered_map<Node*,Node*>&parents, Node *target,int home, int k){
         queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node*temp=q.front();
            q.pop();
            if(temp->left){
                parents[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parents[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    
    
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        unordered_map<Node*,Node*>parents;
        Node*target = findTarget(root,home,k);
        Parents(root,parents,target, home,k);
        
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        q.push(target);
        vis[target]=true;
        int sum=0;
        int level=0;
        while(!q.empty()){
            int n = q.size();
            if(level>k){
                break;
            }
            level++;
            for(int i=0;i<n;i++){
                Node*curr = q.front();
                q.pop();
                sum+=curr->data;
                if(curr->left&&!vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right&&!vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parents[curr]&&!vis[parents[curr]]){
                    q.push(parents[curr]);
                    vis[parents[curr]]=true;
                }
            }
        }
        return sum;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends