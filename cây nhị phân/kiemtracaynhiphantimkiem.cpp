#include<bits/stdc++.h>
// #include<stack>
// #include<queue>
// #include<string>
// #include<math.h>
// #include<list>
// #include<iostream>
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
		if (x < t->data) 
			t->left = insert(t->left, x);
        else 
        	t->right = insert(t->right, x);
	}
    return t;
}
void LRN(Node *root) {
    if (root) {
        LRN(root->left);
        LRN(root->right);
        cout << root->data<<" ";
    }
}
int b[1001],i=0;
void LNR(Node *root){
    if (root) {
        LNR(root->left);
        // cout<<root->data<<" ";
        b[i++]=root->data;
        LNR(root->right);
    }
}
int main(){
    FAST()
    BEGIN(){
        int n;
        cin>>n;
        int x,a[n];
        i=0;
        Node * root = NULL;
        FOR(i,0,n-1){
            cin >> a[i];
            root = insert(root,a[i]);
        }
        LNR(root);
        x=0;
        FOR(j,0,n-1){
            if(a[j]!=b[j]) {
                cout<<x;
                x=1;
                break;
            }
        }
        if(x==0)
            cout<<1;
        cout<<endl;
    }           
}