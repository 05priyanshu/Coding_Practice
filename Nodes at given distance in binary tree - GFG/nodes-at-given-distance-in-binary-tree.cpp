//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution{
public:
    unordered_map<Node*, Node*> parents;
    Node* target_node;
    void parent_finder(Node* root, Node* parent){
        if(!root){
            return;
        }
        parents[root] = parent;
        parent_finder(root -> left, root);
        parent_finder(root -> right, root);
    }
    void find(Node* root, int target, bool &status){
        if(!root){
            return;
        }
        if(root -> data == target and status == false){
            target_node = root;
            status = true;
            return;
        }
        find(root -> left, target, status);
        find(root -> right, target, status);
    }
    vector <int> KDistanceNodes(Node* root, int target , int k){
        parent_finder(root, NULL);
        queue<pair<Node*, int>> q;
        bool status = false;
        find(root, target, status);
        q.push({target_node, k});
        unordered_map<Node*, bool> visited;
        vector<int> ans;
        visited[target_node] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* present = q.front().first;
                int position = q.front().second;
                q.pop();
                if(position == 0){
                    ans.push_back(present -> data);
                }
                if(present -> left and position > 0 and visited[present -> left] == false){
                    q.push({present -> left, position - 1});
                    visited[present -> left] = true;
                }
                if(present -> right and position > 0 and visited[present -> right] == false){
                    q.push({present -> right, position - 1});
                    visited[present -> right] = true;
                }
                if(parents[present] and position > 0 and visited[parents[present]] == false){
                    q.push({parents[present], position - 1});
                    visited[parents[present]] = true;
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends