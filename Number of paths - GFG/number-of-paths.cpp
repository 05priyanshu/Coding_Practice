//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

class Solution {
public:
    int mod = 1000000007;

    long numberOfPaths(int M, int N) {
        int n = M + N - 2;
        int r = min(M - 1, N - 1);
        long res = 1;

        for (int i = 1; i <= r; i++) {
            res = (res * (n - r + i) % mod * modInverse(i, mod)) % mod;
        }
        return res;
    }

    long modInverse(int a, int b) {
        int x = 1, y = 0;
        while (a > 1) {
            int q = a / b, temp = b;
            b = a % b;
            a = temp;
            temp = y;
            y = x - q * y;
            x = temp;
        }
        return x < 0 ? x + mod : x;
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