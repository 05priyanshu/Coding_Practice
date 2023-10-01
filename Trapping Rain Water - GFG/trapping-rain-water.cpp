//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        int leftmax=arr[0],rightmax=arr[n-1],i;
        int maxleft[n],maxright[n];
        long long sum=0;
        if(n<=2) return 0;
        for(i=0;i<n;i++){
            
            leftmax=max(leftmax,arr[i]);
            maxleft[i]=leftmax;
        }
        for(i=n-1;i>=0;i--){
            rightmax=max(arr[i],rightmax);
            maxright[i]=rightmax;
        }
        for(i=1;i<n-1;i++){
            if(arr[i]<maxleft[i] && arr[i]<maxright[i]){
                sum=sum+ min(maxleft[i],maxright[i])-arr[i];
                
            }
            ////
            
        }
        return sum;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends