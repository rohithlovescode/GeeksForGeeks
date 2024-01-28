//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    
		    int length=A.length();
		    string str;
		    vector<int> count(26,0);
		    
		    queue<char> q;
		    for(int i=0;i<length;i++){
		        char curr=A[i];
		        
		        count[curr-'a']++;
		        
		        if(count[curr-'a']==1){
		            q.push(curr);
		        }
		        if(i==0){
		            str=str+curr;
		        }
		        else if(str[i-1]!='#'&&count[str[i-1]-'a']==1){
		            str=str+str[i-1];
		        }
		        else{
		            while(!q.empty()){
		                if(count[q.front()-'a']==1){
		                    str+=q.front();
		                    break;
		                }
		                q.pop();
		            }
		            if(q.empty()){
		                str+='#';
		            }
		        }
		        
		    }
		    return str;
		    
		}
    
};


















//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends