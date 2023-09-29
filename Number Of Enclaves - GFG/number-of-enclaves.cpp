//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    vector<vector<int>> moves = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int i,int j,vector<vector<int>> &grid) {
        grid[i][j] = 0;
        // cout<<i<<" "<<j<<endl;
        
        for (int k=0;k<4;k++) {
            int ni=i+moves[k][0],nj=j+moves[k][1];
            
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj <= grid[0].size() && grid[ni][nj] == 1)
                dfs(ni,nj,grid); 
        }
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int m=grid.size(),n=grid[0].size();
        
        for (int i=0;i<m;i++) {
            if (grid[i][0]) dfs(i,0,grid);
            if (grid[i][n-1]) dfs(i,n-1,grid);
        }
        
        for (int j=0;j<n;j++) {
            if (grid[0][j]) dfs(0,j,grid);
            if (grid[m-1][j]) dfs(m-1,j,grid);
        }
        
        int ans=0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++){
                // cout<<grid[i][j]<<" ";
                if (grid[i][j] == 1) ans++;
            }
            // cout<<endl;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends