//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        if (N==1) return false;
        
        long long factorSum=1;
        
        for(long long d=2;d*d<=N;d++)
            if (N%d == 0) factorSum += d*d == N ? d : d + N/d;
        
        return factorSum == N;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends