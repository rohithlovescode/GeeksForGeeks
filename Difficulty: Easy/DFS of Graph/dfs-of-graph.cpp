//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        map<int,bool> visited;
        stack<int> s;
        vector<int> dfs;
        
        s.push(0);
        visited[0]=true;
        dfs.push_back(0);
        
        while(!s.empty()){
            int top=s.top();
            for(int i=0;i<adj[top].size();i++){
                if(!visited[adj[top][i]]){
                    visited[adj[top][i]]=true;
                    dfs.push_back(adj[top][i]);
                    s.push(adj[top][i]);
                    break;
                }else if(adj[top].size()-1==i){
                    s.pop();
                }
                
            }
        }
        return dfs;
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