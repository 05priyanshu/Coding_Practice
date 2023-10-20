//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

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

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* NEXT;
        while(curr!=NULL){
            NEXT=curr->next;
            curr->next=prev;
            prev=curr;
            curr=NEXT;
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        Node* curr = head;
        bool ans=true;
        while(curr!=NULL&& ans==true){
            if(curr->next==NULL && curr->data==9){
                curr->data=1;
                Node* temp=new Node(0);
                temp->next=head;
                head=temp;
                curr=curr->next;
                
            }
            else if(curr->data==9){
                curr->data=0;
                curr=curr->next;
            }
            else{
                curr->data+=1;
                curr=curr->next;
                ans=false;
            }
        }
        head=reverse(head);
        return head;
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends