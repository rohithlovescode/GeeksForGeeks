//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int MOD=1000000007;
    long long solve(vector<int> & dp,int n,int k){
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=((solve(dp,n-2,k)*(k-1))%MOD+(solve(dp,n-1,k)*(k-1))%MOD)%MOD;
        
        return dp[n];
        
    }
    long long countWays(int n, int k){
        vector<int> dp(n+1,-1);
        dp[1]=k;
        dp[2]=(1LL*k*k)%MOD;
        long long ans=solve(dp,n,k);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends