//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* reverse(struct Node* head) {
        Node* prev = NULL, *curr = head;
        while(curr) {
            Node* next = curr->next;
            
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void print(struct Node* head) {
        while(head) {
            cout << head->data << "->";
            head = head->next;
        } cout << "NULL"; cout << endl;
    }
    
    struct Node* modifyTheList(struct Node *head) {
        //add code here.
        struct Node *slow = head, *fast = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        struct Node* middle = slow;
        if(fast != NULL) middle = middle->next;
        
        middle = reverse(middle);
        
        struct Node* start = head;
        struct Node* mid = middle;
        
        while(mid) {
            int left = start->data;
            int right = mid->data;
            
            int newLeft = right - left;
            int newRight = left;
            
            start->data = newLeft;
            mid->data = newRight;
            
            start = start->next;
            mid = mid->next;
        }
        
        middle = reverse(middle);
        
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends