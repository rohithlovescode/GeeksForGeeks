//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        vector<int> pos,neg;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }else{
                neg.push_back(arr[i]);
            }
        }
        int posSize=pos.size();
        int negSize=neg.size();
        
        int index=0;
        for(int i=0;i<posSize;i++){
            arr[index]=pos[i];
            index++;
        }
        for(int i=0;i<negSize;i++){
            arr[index]=neg[i];
            index++;
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends