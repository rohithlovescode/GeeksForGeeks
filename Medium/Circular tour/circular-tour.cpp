//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int front=0;
        int rear=0;
        int leftPetrol=0;
        
        while(true){
            if((leftPetrol+p[rear].petrol-p[rear].distance)<0){
                if((rear+1)%n<=front){
                    return -1;
                }
                else{
                    leftPetrol=0;
                    front=(rear+1)%n;
                    rear=front;
                }
                continue;
            }
            else{
                leftPetrol=leftPetrol+(p[rear].petrol-p[rear].distance);
                rear=(rear+1)%n;
            }
            if(rear==front){
                return front;
            }
        }
       //Your code here
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends