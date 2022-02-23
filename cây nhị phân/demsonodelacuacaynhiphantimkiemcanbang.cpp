/*
2

11

40  28  45 38  33  15  25  20  23  35  30

10

1  2  3  4  5  6  7  8  9  10
*/
#include<bits/stdc++.h>
using namespace std;
#define Nothing					"mikey"
#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long

int MOD = 1e9 + 7;

struct node { 
    int data; 
    node* left; 
    node* right; 
}; 
  
node* createNode(int data); 
node* sortALV(int arr[], int start, int end){
    if(start>end) return NULL;
    int mid = (start + end) / 2;
    node *root= createNode(arr[mid]);
    root->left = sortALV(arr,start,mid - 1);
    root->right = sortALV(arr,mid+1,end);
    return root;
}

void printPreOrder(node* node);

void printPostorder(node* Node);

void printInorder(node* Node);
int count1=0;
void count(node* Node);
int main() { 
    faster()
    run(){
        count1=0;
        int n; cin >> n;
        int arr[n];
        FOR(i,0,n-1) cin >> arr[i];
        sort(arr,arr+n);
        node *root = sortALV(arr, 0, n-1); 
        count(root);
        cout<<count1; 
       cout<<"\n";
    }
    return EXIT_SUCCESS; 
} 

node* createNode(int data)  { 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL;
    return Node; 
} 

void printPostorder(node* Node) {
    if (Node == NULL)
        return;
    printPostorder(Node->left);
    printPostorder(Node->right);
    cout << Node->data << " ";
}

void printPreOrder(node* node) { 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    printPreOrder(node->left); 
    printPreOrder(node->right); 
} 

void printInorder(node* Node) {
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << Node->data << " ";
    printInorder(Node->right);
}

void count(node* Node) {
    if (Node == NULL) return;
    if(Node->left==NULL && Node->right==NULL) count1++;
    count(Node->left);
    count(Node->right);
}