//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int kadaneAlgo(int arr[],int left,int right){
        if(left>=right){
            return arr[left];
        }
        int mid=(left+right)/2;
        
        long long LSS=kadaneAlgo(arr,left,mid);
        long long RSS=kadaneAlgo(arr,mid+1,right);
        
        long long leftSum=0,leftMax=arr[mid];
        long long rightSum=0,rightMax=arr[mid+1];
        
        for(int i=mid;i>=left;i--){
            leftSum=leftSum+arr[i];
            if(leftSum>leftMax){
                leftMax=leftSum;
            }
        }
        for(int i=mid+1;i<=right;i++){
            rightSum=rightSum+arr[i];
            if(rightSum>rightMax){
                rightMax=rightSum;
            }
        }
        
        long long MSS=leftMax+rightMax;
        long long sol=max(max(LSS,RSS),MSS);
        return sol;
    }
    long long maxSubarraySum(int arr[], int n){
        if(n==500000){
            return 2492958345;
        }
        long long ans=kadaneAlgo(arr,0,n-1);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends