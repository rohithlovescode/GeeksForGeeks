#include <iostream>
using namespace std;

int main() {
    
    string s;
    int n;
    
    cin>>n;
    
    while(n--){
        int ones=0,zeros=0;
        int k;
        cin>>k;
        cin>>s;
        bool completed=false;
        
        
        for(char ch:s){
            if(ch=='0'){
                zeros++;
            }else{
                ones++;
            }
            if(ones>zeros){
                cout<<"no"<<endl;
                completed=true;
                break;
            }
        }
        
        if(completed){
            continue;
        }
        if(ones!=zeros){
            cout<<"no"<<endl;
            continue;
        }
        cout<<"yes"<<endl;
        
    }
	return 0;
}