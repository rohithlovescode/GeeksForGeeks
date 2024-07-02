//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        
        map<int, bool> visited;
        queue<int> q;
        vector<int> indegree(V,0);
        map<int,bool> inQueue;
        
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        //pushing everything with indegree 0
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
                inQueue[i]=true;
            }
        }
        
        
        vector<int> sol;
        while(!q.empty()){
            int front=q.front();
            sol.push_back(front);
            visited[front]=true;
            q.pop();
            //now we need to update the inorder then add all those with indegree 0
            for(int i=0;i<adj[front].size();i++){
                int node=adj[front][i];
                indegree[node]--;
                if(indegree[node]==0&&!inQueue[node]){
                    q.push(node);
                }
            }
            
        }
        return sol;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends