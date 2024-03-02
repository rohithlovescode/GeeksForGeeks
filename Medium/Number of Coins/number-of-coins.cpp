//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int solve(vector<int> & coins,int V,vector<int> & dp){
        if(V<0){
            return INT_MAX;
        }
        if(V==0){
            return 0;
        }
        int n=coins.size();
        if(dp[V]!=-1)
            return dp[V];
        int mini= INT_MAX;
        for(int i=0;i<n;i++){
            int ans=solve(coins,V-coins[i],dp);
            if(ans!=INT_MAX){
                mini=min(mini,ans+1);
            }
        }
        dp[V]=mini;
        return dp[V];
    }
	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    vector<int> dp(V+1,-1);
	    
	    int ans=solve(coins,V,dp);
	    if (ans==INT_MAX){
	        return -1;
	    }
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends