//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    void heapify(vector<int>& heap,int index){
        int left=2*index;
        int right=2*index+1;
        
        int largest=index;
        
        if(left<heap.size()&&heap[left]>heap[largest]){
            largest=left;
        }
        
        if(right<heap.size()&&heap[right]>heap[largest]){
            largest=right;
        }
        
        if(largest!=index){
            swap(heap[largest],heap[index]);
            heapify(heap,largest);
        }
        
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        ans.push_back(0);
        
        for(int i=0;i<n;i++){
            ans.push_back(a[i]);
        }
        for(int j=0;j<m;j++){
            ans.push_back(b[j]);
        }
        
        int size=m+n;
        for(int i=size/2;i>0;i--){
            heapify(ans,i);
        }
        ans.erase(ans.begin());
        return ans;
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends