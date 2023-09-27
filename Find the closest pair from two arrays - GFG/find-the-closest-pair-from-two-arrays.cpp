//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int res_l,res_r,diff=INT_MAX;
        vector <int> ans;
        int r=m-1,i=0;
        while(i<n && r>=0){
            if(abs(arr[i]+brr[r]-x)<diff){
                res_l =i;
                res_r =r;
                diff=abs(arr[i]+brr[r]-x);
            }
            if(arr[i]+brr[r]>x){
                r--;
            }
            else{
                i++;
            }
        }
        
        ans.push_back(arr[res_l]);
        ans.push_back(brr[res_r]);
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends