#include<bits/stdc++.h>
    #define ll long long
// test

    #define BEGIN() int t;cin>>t;while(t--)
    #define FAST() ios_base::sync_with_stdio(0);cin.tie(0);
	
// acronym
    #define pob pop_back
    #define EL printf("\n")
    #define pb push_back
    #define FOR(i,l,r) for (int i=l;i<=r;i++)
    #define FORD(i,r,l) for (int i=r;i>=l;i--)
    
    using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
Node *insert(Node *t, int x){
	if (t == NULL){
		Node *temp = new Node;
		temp->data =x;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	} 
    else {
		if (x < t->data) {
			t->left = insert(t->left, x);
		} 
        else {
			t->right = insert(t->right, x);
		}
	}
    return t;
}

void printPreOrder(Node* node);

void printPostorder(Node* node);

void printInorder(Node* node);

int main(){
    FAST()
    BEGIN(){
        int n;
        cin>>n;
        int arr[n];
        FOR(i,0,n-1) cin >> arr[i];
        Node * root = NULL;
        FOR(i,0,n-1){
            root = insert(root,arr[i]);
        }
        printPreOrder(root);
        cout<<endl;
    }           
}
void printPostorder(Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

void printPreOrder(Node* node) { 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    printPreOrder(node->left); 
    printPreOrder(node->right); 
} 

void printInorder(Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
