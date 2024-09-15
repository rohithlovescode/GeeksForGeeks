//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void merge(vector<long long> & arr,int left,int mid,int right,long long int& ans){
        int m=mid-left+1;
        int n=right-mid;
        if(left>=right){
            return;
        }
        
        vector<long long> leftArr(m);
        vector<long long> rightArr(n);
        for(int i=0;i<m;i++){
            leftArr[i]=arr[left+i];
        }
        for(int i=0;i<n;i++){
            rightArr[i]=arr[mid+i+1];
        }
        int leftInd=0;
        int rightInd=0;
        int ind=left;
        while(leftInd<m&&rightInd<n){
            if(leftArr[leftInd]<=rightArr[rightInd]){
                arr[ind]=leftArr[leftInd];
                leftInd++;
                ind++;
            }else{
                arr[ind]=rightArr[rightInd];
                rightInd++;
                ind++;
                ans+=(m-leftInd);
            }
        }
        while(leftInd<m){
            
            arr[ind]=leftArr[leftInd];
            leftInd++;
            ind++;
        }
        while(rightInd<n){
            arr[ind]=rightArr[rightInd];
            rightInd++;
            ind++;
        }
        leftArr.clear();
        rightArr.clear();
        
    }
    void mergeSort(vector<long long> &arr,int left,int right,long long int& ans){
        
        if(left>=right){
            return;
        }
        int mid=left+(right-left)/2;
        
        mergeSort(arr,left,mid,ans);
        mergeSort(arr,mid+1,right,ans);
        
        
        merge(arr,left,mid,right,ans);
    }
    long long int inversionCount(vector<long long> &arr) {
        long long int ans=0;
        vector<long long> tempArr=arr;
        int n=arr.size();
        
        
        mergeSort(arr,0,n-1,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends