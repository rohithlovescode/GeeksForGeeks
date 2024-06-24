//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(int V, vector<int> adj[]) {
        map<int,bool> visited;
        map<int,int> parent;
        
        for(int start=0;start<V;start++){
            if(visited[start]){
                continue;
            }
        queue<int> q;
        q.push(start);
        parent[start]=-1;
        
        while(!q.empty()){
            int front=q.front();
            visited[front]=true;
            q.pop();
            
            for(int i=0;i<adj[front].size();i++){
                if(adj[front][i]==parent[front]){
                    continue;
                }
                if(visited[adj[front][i]]==true){
                    return true;
                }
                q.push(adj[front][i]);
                parent[adj[front][i]]=front;
            }
            
        }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends