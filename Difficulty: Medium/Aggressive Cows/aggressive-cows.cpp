//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool solve(int leng,const vector<int>& stalls,const int& k){
        int temp=0;
        int cowsLeft=k-1;//first cow is at 0th position
        for(int i=1;i<stalls.size()&&cowsLeft>0;i++){
            temp+=stalls[i];
            temp-=stalls[i-1];
            if(temp>=leng){
                temp=0;
                cowsLeft--;
            }
        }
        return cowsLeft<=0;
    }
    void solveBS(const vector<int>& stalls,int left,int right,int& ans,const int& k){
        if(left>right){
            return;
        }
        int mid=left+(right-left)/2;
        if(solve(mid,stalls,k)){
            ans=mid;
            solveBS(stalls,mid+1,right,ans,k);
        }else{
            solveBS(stalls,left,mid-1,ans,k);
        }
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int ans=-1;
        int n=stalls.size();
        int left=0,right=stalls[n-1]-stalls[0];
        
        solveBS(stalls,left,right,ans,k);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends