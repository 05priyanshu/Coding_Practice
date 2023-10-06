//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
   struct Node *reverse (struct Node *head)
    { 
        Node *current =head;
        Node * pre = NULL;
        Node * next_node = head->next;
        int c=0;
        while(current!=NULL){
            next_node = current->next;
            current->next =pre;
            pre = current;
            current = next_node;
            c++;
        }
        return pre;
    }
    void rearrange(struct Node *odd)
    {
        Node * start = odd;
        Node * second = odd->next;
        Node * oddstart = odd->next;
        while(start->next!=NULL && second->next!=NULL){
            start->next = second->next;
            start = start->next;
            second->next = start->next;
            second = second->next;
        }
        if(odd->next!=NULL){
            Node *restart = reverse(oddstart);
        start->next = restart;
        }
        
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends