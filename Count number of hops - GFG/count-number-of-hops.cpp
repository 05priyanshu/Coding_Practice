//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    #define MOD 1000000007
    public:
    //Function to count the number of ways in which frog can reach the top.
    
    long long solve(int n, int i,long long dp[]){
        if(i==n){
            return 1;
        }
        if(n<i){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i] =(solve(n,i+1,dp)+solve(n,i+2,dp)+solve(n,i+3,dp))%MOD;
        return dp[i];
    }
     
    long long countWays(int n)
    {
        long long dp[n];
        for(int i=0;i<n;i++){
            dp[i]=-1;
        }
        long long ans;
        ans=solve(n,0,dp)%MOD;
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends