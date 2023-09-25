//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Compare {
public:
    bool operator()(vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    }
};

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        set<pair<int,int>> s;
        vector<int> ans;
        
        pq.push({A[N-1]+B[N-1],N-1,N-1});
        
        while (!pq.empty() && K--) {
            vector<int> x = pq.top();
            pq.pop();
            ans.push_back(x[0]);
            
            if (x[1]-1 >= 0 && s.find({x[1]-1,x[2]}) == s.end()) {
                s.insert({x[1]-1,x[2]});
                pq.push({A[x[1]-1]+B[x[2]],x[1]-1,x[2]});
            }
            
            if (x[2]-1 >= 0 && s.find({x[1],x[2]-1}) == s.end()) {
                s.insert({x[1],x[2]-1});
                pq.push({A[x[1]]+B[x[2]-1],x[1],x[2]-1});
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends