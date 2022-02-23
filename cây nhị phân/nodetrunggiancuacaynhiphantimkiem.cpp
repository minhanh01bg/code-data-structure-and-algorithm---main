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
int Max=0;
void count(Node* t,int d){
    if(t==NULL) return;
    if(t->left!=NULL){
        Max=max(Max,d);
        count(t->left,d++);
    }
    if(t->right!=NULL){
        Max=max(Max,d);
        count(t->right,d++);
    } 
    if(t->left== NULL && t->right== NULL) {
        Max=max(Max,d+1);
    }
}
int dem=0;
void count(Node *t){
    if(t== NULL) return;
    if(t->left != NULL || t->right != NULL)
        dem++;
    count(t->left);
    count(t->right);
}
int main(){
    FAST()
    BEGIN(){
        int n;
        cin>>n;
        int x=0;
        Node* root=NULL;
        FOR(i,1,n){
            cin>>x;
            root= insert(root,x);
        }
        dem=0;
        count(root);
        cout<<dem;
        cout<<endl;
    }
}