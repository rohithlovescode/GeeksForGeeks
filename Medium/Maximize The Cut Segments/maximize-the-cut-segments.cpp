//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int solve(int n,int& x,int& y, int& z,vector<int> & dp){
        if(n<0){
            return INT_MIN;
        }
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int xRec=solve(n-x,x,y,z,dp);
        int yRec=solve(n-y,x,y,z,dp);
        int zRec=solve(n-z,x,y,z,dp);
        dp[n]= max(xRec,max(yRec,zRec))+1;
        return dp[n];
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int count=0;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        int ans=solve(n,x,y,z,dp);
        if(ans<0){
            return 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends