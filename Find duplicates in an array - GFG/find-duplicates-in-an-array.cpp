//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // set<int> ans;
        unordered_map<int,int> hash;
        vector <int>anss;
        // set<int>::iterator itr;
        int i;
        for(i=0;i<n;i++){
            hash[arr[i]]++;
        }
        for(i=0;i<n;i++){
            if(hash[arr[i]]>1){
                anss.push_back(arr[i]);
                hash[arr[i]]=0;
                
            }
        }
        // for (itr = ans.begin();itr != ans.end(); itr++){
        //     anss.push_back(*itr);
        // }
        if(!anss.empty()) {
            sort(anss.begin(),anss.end());
            return anss;
            
        }
        
        anss.push_back(-1);
        return anss;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends