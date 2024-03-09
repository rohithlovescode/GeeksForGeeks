//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class node{
public:
    int data;
    int i;
    int j;
};
class compare{
public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> sol;
        priority_queue<node*,vector<node*>,compare> minHeap;
        for(int i=0;i<arr.size();i++){
            node* newNode=new node();
            
            newNode->data=arr[i][0];
            newNode->i=i;
            newNode->j=0;
            
            minHeap.push(newNode);
        }
        
        while(!minHeap.empty()){
            node* curr=minHeap.top();
            minHeap.pop();
            
            sol.push_back(curr->data);
            if((curr->j+1)<arr[curr->i].size()){
                curr->j++;
                curr->data=arr[curr->i][curr->j];
                minHeap.push(curr);
            }
        }
        return sol;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends