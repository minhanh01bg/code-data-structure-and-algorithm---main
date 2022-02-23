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

node *insert(node *t, int x){
	if (t == NULL){
		node *temp = new node;
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
node* createNode(int data)  { 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL;
    return Node; 
} 
// đưa cây về trạng thái ban đầu
node* constructTree(int pre[], int size) {
    stack<node* > s;
    int i;
    struct node* root=createNode(pre[0]);
    struct node* temp;
    struct node* top_node;
    s.push(root);
    for(i=1;i<size;i++) {
        temp=NULL;
        while(!s.empty()&&pre[i]>(s.top()->data)) {
                temp=s.top();
                s.pop();
            }
            if(temp==NULL){
                top_node=s.top();
                top_node->left=createNode(pre[i]);
                s.push(top_node->left);
            }else {
                temp->right=createNode(pre[i]);
                s.push(temp->right);
            }
    }
    return root;
}

int Count(node* t){
    if(t==NULL) return NULL;
    return 1+max(Count(t->left),Count(t->right));    
}
main(){
    faster()
    run(){
        int n;
        cin>>n;
        int x;
        node* root=NULL;
        int a[n];
        FOR(i,0,n-1) cin>>a[i];
        root=constructTree(a,n);
        cout<<Count(root)-1;
        cout<<endl;
    }
}
