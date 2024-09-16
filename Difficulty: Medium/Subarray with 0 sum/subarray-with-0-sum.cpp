//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        vector<int> prefixSum(n);
        prefixSum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=arr[i]+prefixSum[i-1];
        }
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++){
            if(visited[prefixSum[i]]||prefixSum[i]==0){
                return true;
            }
            visited[prefixSum[i]]=true;
        }
        
        
        
        
        return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends