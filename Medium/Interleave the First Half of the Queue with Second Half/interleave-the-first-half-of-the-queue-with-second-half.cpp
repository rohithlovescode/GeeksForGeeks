//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int> sol1;
        vector<int> sol2;
        int n=q.size();
        for(int i=0;i<n;i++){
            int temp=q.front();
            if(i<n/2)
            sol1.push_back(q.front());
            else
            sol2.push_back(q.front());
            q.pop();
            q.push(temp);
        }
        vector<int> ans;
        for(int i=0;i<n/2;i++){
            ans.push_back(sol1[i]);
            ans.push_back(sol2[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends