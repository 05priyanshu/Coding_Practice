//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& visited,int vkey) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0 || visited[i][j] != 0) return 0;
        visited[i][j] = vkey;
        
        return 1 + dfs(i+1,j,grid,visited,vkey)
            + dfs(i-1,j,grid,visited,vkey)
            + dfs(i,j+1,grid,visited,vkey)
            + dfs(i,j-1,grid,visited,vkey);
    }
    
    void fill(int i,int j,vector<vector<int>>& grid,int f) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if (grid[i][j] != 1) return;
        
        grid[i][j] = f;
        fill(i+1,j,grid,f);
        fill(i-1,j,grid,f);
        fill(i,j+1,grid,f);
        fill(i,j-1,grid,f);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = -1,temp;
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int vkey = 1;
        
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == 1) {
                    temp = dfs(i,j,grid,visited,vkey++);
                    fill(i,j,grid,temp);
                }
            }
        }
        
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[0].size();j++) {
                if (grid[i][j] == 0) {
                    temp = 1;
                    int v1=0,v2=0,v3=0;
                    if (i+1<grid.size()) {temp += grid[i+1][j];v1=visited[i+1][j];}
                    if (i-1<grid.size() && v1 != visited[i-1][j]) {temp += grid[i-1][j];v2=visited[i-1][j];}
                    if (j+1<grid[0].size() && v1 != visited[i][j+1] && v2 != visited[i][j+1]) {temp += grid[i][j+1];v3=visited[i][j+1];}
                    if (j-1<grid[0].size() && v1 != visited[i][j-1] && v2 != visited[i][j-1] && v3 != visited[i][j-1]) temp += grid[i][j-1];
                    
                    ans = max(ans,temp);
                }
            }
        }
        
        if (ans == -1) return grid.size()*grid[0].size();
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends