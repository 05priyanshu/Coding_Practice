//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 
 #define MOD 1000000007

class Solution{
	public:
	int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        dp[0][0] = 1;
        
        for (int i=1;i<=n;i++) {
            dp[i][0] = dp[i-1][0];
            if (arr[i-1] == 0) dp[i][0] = (dp[i][0]*2)%MOD;
            
            for (int j=1;j<=sum;j++) {
                dp[i][j] = dp[i-1][j];
                if (j >= arr[i-1] && dp[i-1][j-arr[i-1]] > 0) dp[i][j] = (dp[i][j] + dp[i-1][j-arr[i-1]])%MOD;
            }
        }
        
        // for (auto x:dp) {
        //     for (auto y:x) cout<<y<<" ";
        //     cout<<endl;
        // }
        
        return dp[n][sum];
	}
};
 
 

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends