//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    unordered_map<Node*,int> mapping;
    int maxi=INT_MIN;
    int mini=INT_MAX;
    
    void mapNodes(Node* root,int num){
        if(root==NULL){
            return;
        }
        if(num<mini){
            mini=num;
        }
        if(num>maxi){
            maxi=num;
        }
        mapping[root]=num;
        mapNodes(root->left,num-1);
        mapNodes(root->right,num+1);
        
    }
    void solve(Node* root,vector<int> &sol){
        vector<vector<int>> temp(maxi-mini+1);
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            Node* curr= q.front();
            int index=mapping[curr]-mini;
            temp[index].push_back(curr->data);
            
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            q.pop();
        }
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].size();j++){
                sol.push_back(temp[i][j]);
            }
        }
    }
    public:
    
    vector<int> verticalOrder(Node *root)
    {
        vector<int> sol;
        
        if(root==NULL){ return sol;}
        
        mapNodes(root,0);
        
        solve(root,sol);
        return sol;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends