//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range

    class compare{
        public:
        bool operator()(pair<int,int> a,pair<int,int> b){
            return a.first>b.first;
        }
    };
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> minHeap;
        //first int indecates number, second is the representation of which list(index)
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        
        vector<int> indices(k,0);
        for(int i=0;i<k;i++){
            pair<int,int> currPair(KSortedArray[i][0],i);
            
            mini=min(mini,KSortedArray[i][0]);
            maxi=max(maxi,KSortedArray[i][0]);
            
            minHeap.push(currPair);
        }
        int temp_maxi=maxi;
        int temp_mini=mini;
        
        while(true){
            pair<int,int> currPair=minHeap.top();
            minHeap.pop();
            
            indices[currPair.second]++;
            int index=indices[currPair.second];
            
            if(index>=n){
                break;
            }
            if(KSortedArray[currPair.second][index]>temp_maxi){
                temp_maxi=KSortedArray[currPair.second][index];
            }
            minHeap.push(make_pair(KSortedArray[currPair.second][index],currPair.second));
            currPair=minHeap.top();
            temp_mini=currPair.first;
            if((temp_maxi-temp_mini)<(maxi-mini)){
                maxi=temp_maxi;
                mini=temp_mini;
            }
        }
        return make_pair(mini,maxi);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends