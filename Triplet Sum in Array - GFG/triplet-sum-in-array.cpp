//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        int i,j,k ;
        
        for(i=0;i<n;i++){
            unordered_set<int> hash;
            for(j=i+1;j<n;j++){
                int third = X-(A[i]+A[j]);
                if(hash.find(third)!=hash.end()){
                    return true;
                }
                hash.insert(A[j]);
            }
            
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends