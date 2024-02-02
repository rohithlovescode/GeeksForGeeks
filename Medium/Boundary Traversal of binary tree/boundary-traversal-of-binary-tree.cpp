//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    void leftTraversal(Node* root,vector<int> &solution){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            return;
        }
        solution.push_back(root->data);
        if(root->left!=NULL)
            leftTraversal(root->left,solution);
        else
            leftTraversal(root->right,solution);
            
    }
    void leafTraversal(Node* root,vector<int> & solution){
        if(root==NULL){
            return;
        }
        leafTraversal(root->left,solution);
        
        if(root->left==NULL&&root->right==NULL){
            solution.push_back(root->data);
        }
        
        leafTraversal(root->right,solution);
    }
    void rightTraversal(Node* root,vector<int> & solution){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            return;
        }
        
        
        if(root->right==NULL){
            rightTraversal(root->left,solution);
        }else{
            rightTraversal(root->right,solution);
        }
        
        solution.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        
        vector<int> solution;
        if(root==nullptr){
            return solution;
        }
        solution.push_back(root->data);
        if(root->left==NULL&&root->right==NULL){
            return solution;
        }
        leftTraversal(root->left,solution);
        leafTraversal(root,solution);
        rightTraversal(root->right,solution);
        return solution;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends