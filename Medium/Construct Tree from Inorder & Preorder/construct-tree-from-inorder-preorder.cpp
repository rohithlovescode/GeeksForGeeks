//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    Node* solve(int in[],int pre[],int &preOrderIndex,int leftIndex,int rightIndex,int n){
        if(preOrderIndex>=n||leftIndex>rightIndex){
            return NULL;
        }
        int inOrderIndex=-1;
        for(int i=leftIndex;i<=rightIndex;i++){
            if(in[i]==pre[preOrderIndex]){
                inOrderIndex=i;
            }
        }
        if(inOrderIndex==-1){
            return NULL;
        }
        Node* newNode= new Node(pre[preOrderIndex]);
        preOrderIndex++;
        newNode->left=solve(in,pre,preOrderIndex,leftIndex,inOrderIndex-1,n);
        newNode->right=solve(in,pre,preOrderIndex,inOrderIndex+1,rightIndex,n);
        return newNode;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int leftIndex=0;
        int rightIndex=n-1;
        int preOrderIndex=0;
        Node* root=solve(in,pre,preOrderIndex,leftIndex,rightIndex,n);
        
        return root;
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends