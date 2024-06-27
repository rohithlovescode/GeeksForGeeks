//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> sol;
        stack<int> s;
        s.push(0);
        sol.push_back(0);
        unordered_map<int,bool> visited;
        visited[0]=true;
        
        while(!s.empty()){
            int top=s.top();
            
            
            int n=adj[top].size();
            for(int i=0;i<n;i++){
                int curr=adj[top][i];
                if(!visited[curr]){
                    visited[curr]=true;
                    sol.push_back(curr);
                    s.push(curr);
                    break;
                }
            }
            if(top==s.top()){
                s.pop();
            }
        }
        return sol;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends