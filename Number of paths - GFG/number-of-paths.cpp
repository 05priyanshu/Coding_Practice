//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution
{
    long long MOD = 1000000007;

public:
    long long numberOfPaths(int M, int N) {
        long long ans = 1;

        for (long long i = 1; i <= M - 1; i++) {
            ans = (ans * (N + i - 1)) % MOD;
            ans = (ans * modInverse(i)) % MOD;
        }

        return ans;
    }

    // Function to calculate modular inverse using Fermat's Little Theorem
    long long modInverse(long long a) {
        long long result = 1;
        long long b = MOD - 2; // Using Fermat's Little Theorem
        while (b > 0) {
            if (b % 2 == 1) {
                result = (result * a) % MOD;
            }
            a = (a * a) % MOD;
            b /= 2;
        }
        return result;
    }
};






//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends