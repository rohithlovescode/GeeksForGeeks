//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> & m, vector<string>& sol,string curr,int& n, vector<vector<int>> visited){
        if(i<0||j<0||i>=n||j>=n){
            return;
        }
        else if(visited[i][j]==1){
            return;
        }
        else if(m[i][j]==0){
            return;
        }
        if(i==n-1&&j==n-1){
            sol.push_back(curr);
            return;
        }
        
        visited[i][j]=1;
        
        //up
        solve(i-1,j,m,sol,curr+"U",n,visited);
        //down
        solve(i+1,j,m,sol,curr+"D",n,visited);
        //left
        solve(i,j-1,m,sol,curr+"L",n,visited);
        //right
        solve(i,j+1,m,sol,curr+"R",n,visited);
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> sol;
        vector<vector<int>> visited(n,vector<int>(n,0));
        string curr="";
        int i=0,j=0;
        solve(i,j,m, sol,curr,n,visited);
        
        return sol;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends