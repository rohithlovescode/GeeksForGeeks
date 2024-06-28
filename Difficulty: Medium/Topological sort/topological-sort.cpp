//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        stack<int> s;
        stack<int> ans;
        map<int, bool> visited;

        // Iterate through all vertices to handle disconnected graphs
        for (int start = 0; start < V; start++) {
            if (!visited[start]) {
                s.push(start);
                visited[start] = true;

                while (!s.empty()) {
                    int top = s.top();

                    bool allVisited = true;
                    for (int i = 0; i < adj[top].size(); i++) {
                        int curr = adj[top][i];
                        if (!visited[curr]) {
                            visited[curr] = true;
                            s.push(curr);
                            allVisited = false;
                            break;
                        }
                    }

                    if (allVisited) {
                        ans.push(top);
                        s.pop();
                    }
                }
            }
        }

        vector<int> sol;
        while (!ans.empty()) {
            sol.push_back(ans.top());
            ans.pop();
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