//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    void merge(int arr[],int l,int mid,int r){
        
        int size1=mid-l+1;
        int size2=r-mid;
        
        int* arr1=new int[mid-l+1];
        int* arr2=new int[r-mid];
        
        int index1=0;
        int index2=0;
        
        for(int i=l;i<=mid;i++){
            arr1[i-l]=arr[i];
        }
        for(int i=mid+1;i<=r;i++&&index2++){
            arr2[i-mid-1]=arr[i];
        }
        index1=0,index2=0;
        int index=l;
        while(index1<size1&&index2<size2){
            if(arr1[index1]<arr2[index2]){
                arr[index]=arr1[index1];
                index++;
                index1++;
            }else{
                arr[index]=arr2[index2];
                index++;
                index2++;
            }
        }
        while(index1<size1){
            arr[index]=arr1[index1];
            index++;
            index1++;
        }
        while(index2<size2){
            arr[index]=arr2[index2];
            index++;
            index2++;
        }
        
    delete[] arr1;
    delete[] arr2;
    }
    void mergeSort(int arr[],int l,int r){
        if(r<=l){
            return;
        }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr, mid+1,r);
        
        merge(arr, l,mid, r);
    }
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        mergeSort(arr,l,r);
        return arr[l+k-1];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends