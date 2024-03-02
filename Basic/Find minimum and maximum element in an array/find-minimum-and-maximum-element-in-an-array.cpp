//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    pair<long long, long long> getMinMax(long long a[], int n) {
        long long mini=INT_MAX;
        long long maxi=INT_MIN;
        pair<long long, long long> ans=make_pair(mini,maxi);
        for(int i=0;i<n;i++){
            if(a[i]<ans.first){
                ans.first=a[i];
            }
            if(a[i]>ans.second){
                ans.second=a[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(a, n);
        
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends