//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int binSearch(int arr[],int n,int x) {
        int low = 0,high=n-1,mid;
        
        while (low<=high) {
            mid = (low+high)/2;

            if (arr[mid] >= x) high = mid-1;
            else low = mid+1;
        }
        
        return low;
    }
    public:
    vector<int> find(int arr[], int n , int x ){
        int start = binSearch(arr,n,x);
        if (arr[start] != x) return {-1,-1};
        
        int end = binSearch(arr,n,x+1);
        return {start,end-1};
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends