//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    unordered_map<Node*,Node*> parent;
    unordered_map<Node*,bool> visited;
    
    void mapParents(Node* root){
        if(root->left!=NULL){
            parent[root->left]=root;
            mapParents(root->left);
        }
        if(root->right!=NULL){
            parent[root->right]=root;
            mapParents(root->right);
        }
        
    }
    int max=0;
    
    void burn(Node* root,int sol){
        
        if(root==NULL||visited[root]==true){
            return;
        }
        if(sol>max){
            max=sol;
        }
        visited[root]=true;
        burn(root->left,sol+1);
        burn(root->right,sol+1);
        
        Node* parentNode=parent[root];
        burn(parentNode,sol+1);
        
    }
    Node* findNode(Node* root,int target){
        
        if(root==NULL||root->data==target){
            return root;
        }
        Node* left=findNode(root->left,target);
        Node* right=findNode(root->right,target);
        
        if(left==NULL){
            return right;
        }
        return left;
    }
  public:
    int minTime(Node* root, int target) 
    {
        if(root==NULL){
            return 0;
        }
        mapParents(root);
        int sol=0;
        Node* targetNode=findNode(root,target);
        
        burn(targetNode,sol);
        return max;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends