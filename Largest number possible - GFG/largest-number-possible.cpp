//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if (S == 0) {
            if (N == 1) return "0";
            return "-1";
        }
        
        string ans = "";
        for (int i=0;i<N;i++) {
            int x = min(9,S);
            ans += ('0'+x);
            S -= x;
        }
        
        if (S > 0) return "-1";
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends