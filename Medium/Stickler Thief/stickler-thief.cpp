//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int solve(int arr[],int index,int n,vector<int> & dp){
        if(index>=n){
            return 0;
        }
        if(index==n-1){
            return arr[index];
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int temp1=solve(arr,index+2,n,dp);
        int temp2=solve(arr,index+3,n,dp);
        
        dp[index]=max(temp1,temp2)+arr[index];
        return dp[index];
    }
    int FindMaxSum(int arr[], int n)
    {
        vector<int> dp(n+1,-1);
        int temp1=solve(arr,0,n,dp);
        int temp2=solve(arr,1,n,dp);
        return max(temp1,temp2);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends