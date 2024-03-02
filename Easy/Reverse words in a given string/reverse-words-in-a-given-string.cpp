//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string ans;
        
        string temp="";
        int count=0;
        int leng=S.length();
        for(int i=leng-1;i>=0;i--){
            
            if(S[i]=='.'){
                count++;
                if(ans!=""){
                    ans+=".";
                }
                ans=ans+temp;
                temp="";
                
                continue;
            }
            
            temp=S[i]+temp;
        }
        if(count){
            ans+='.';
        }
        ans=ans+temp;
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends