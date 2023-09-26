//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        int size = arr.size();
        int sum = 0;
        
        sort(arr.begin() , arr.end());
        
        for(int i=0 ; i<size ; i++){
            for(int j=i+1 ; j<size ; j++){
                
                sum = k - arr[i] - arr[j];
                
                int left = j+1;
                int right = size-1;
                
                while(left < right){
                    if(sum == arr[left] + arr[right]){
                        ans.push_back({arr[i] , arr[j] , arr[left] , arr[right]});
                        left++;
                        right--;
                    }
                    
                    else if(sum > arr[left] + arr[right]) left++;
                    else if(sum < arr[left] + arr[right]) right--;
                }
            }
        }
        
        sort(ans.begin(), ans.end());
            // Remove duplicates using std::unique
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends