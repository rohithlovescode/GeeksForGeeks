//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(vector<int> &arr, int ind, int k,vector<vector<int>>& dp){
        if(ind==arr.size()-1){
            return 0;
        }
        if(dp[ind][arr[ind]]!=-1){
            return dp[ind][arr[ind]];
        }
        
        int temp=(k-arr[ind])*(k-arr[ind]);
        int a=temp+solve(arr,ind+1,k,dp),b=INT_MAX;
        
        if(arr[ind]+arr[ind+1]<k){
            arr[ind+1]=arr[ind]+arr[ind+1]+1;
            
            b=solve(arr,ind+1,k,dp);
            arr[ind+1]=arr[ind+1]-arr[ind]-1;
        }
        dp[ind][arr[ind]]= min(a,b);
        return dp[ind][arr[ind]];
        
    }
    int solveWordWrap(vector<int> arr, int k) {
        vector<vector<int>> dp(arr.size(),vector<int>(k+1,-1));
        int finalCost=solve(arr,0,k,dp);
        return finalCost;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        string str1;
        getline(cin, str1);

        stringstream ss1(str1);
        int k;
        int num1;
        while (ss1 >> num1) {
            k = num1;
        }
        Solution obj;
        cout << obj.solveWordWrap(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends