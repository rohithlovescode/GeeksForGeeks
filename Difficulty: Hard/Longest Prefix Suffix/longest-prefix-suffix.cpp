//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &s) {
        
        int leng=s.length();
        
        int i=1,prevLPS=0;
        vector<int> lps(leng,0);
        
        while(i<leng){
            if(s[prevLPS]==s[i]){
                lps[i]=prevLPS+1;
                prevLPS++;
                i++;
            }else if(prevLPS==0){
                lps[i]=0;
                i++;
            }
            else{
                prevLPS=lps[prevLPS-1];
            }
        }
        return lps[leng-1];
        // Your code goes here
    }
};


//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.longestPrefixSuffix(str) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends