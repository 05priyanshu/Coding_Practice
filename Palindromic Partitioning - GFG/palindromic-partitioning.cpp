//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void helper(string str,vector<bool> pals[]) {
        for (int i=0;i<str.length();i++) pals[i][i] = true;

        for (int d=1;d<str.length();d++) {
            for (int i=0;i+d<str.length();i++) {
                int j = i+d;

                if (d == 1) 
                    pals[i][j] = (str[i] == str[j]);
                else 
                    pals[i][j] = (pals[i+1][j-1] && str[i] == str[j]);

                // cout<<i<<" "<<j<<" "<<pals[i][j]<<endl;
            }
        }
    }
public:
    int palindromicPartition(string str) {
        vector<bool> pals[str.length()];
        for (int i=0;i<str.length();i++)
            pals[i].resize(str.length(),false);
        helper(str,pals);

        vector<int> minCutDp(str.length(),INT_MAX);
        minCutDp[0] = 0;

        for (int i=1;i<str.length();i++) {
            if (pals[0][i]) {
                minCutDp[i] = 0;
                continue;
            }

            for (int j=i;j>=1;j--) {
                if (pals[j][i])
                    minCutDp[i] = min(minCutDp[i],minCutDp[j-1]+1);
            }
        }

        return minCutDp[str.length()-1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends