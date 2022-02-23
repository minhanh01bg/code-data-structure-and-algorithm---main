#include<bits/stdc++.h>
using namespace std;

#define Nothing					"mikey"

#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

struct node{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node NODE;
typedef NODE* tree;

tree createNode(int x){
	NODE*p=new NODE;
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}

int isLeaf(tree Node) {
    if(Node == NULL)
        return 0;
    if(Node->left == NULL && Node->right == NULL)
        return 1;
    return 0;
}

int isSumtree(tree Node) {
    int ls;
    int rs;
    if(Node == NULL || isLeaf(Node))
        return 1;
 
    if( isSumtree(Node->left) && isSumtree(Node->right)) {
        if(Node->left == NULL)
            ls = 0;
        else if(isLeaf(Node->left))
            ls = Node->left->data;
        else
            ls = 2 * (Node->left->data);
        if(Node->right == NULL)
            rs = 0;
        else if(isLeaf(Node->right))
            rs = Node->right->data;
        else
            rs = 2 * (Node->right->data);
        return(Node->data == ls + rs);
    }
    return 0;
}

int main(){
	int test; 
	cin>>test;
	while(test--){
	    int n, parentValue, childValue;
		char pos;
		cin >> n >> parentValue >> childValue >> pos;

		vector<tree> vNote;
		tree root = createNode(parentValue);
		vNote.push_back(root);

		if(pos == 'L') {
			root->left = createNode(childValue);
			vNote.push_back(root->left);
		} 
		else {
			root->right = createNode(childValue);
			vNote.push_back(root->right);
		}
		
		FOR(i,2,n) {
			cin >> parentValue >> childValue >> pos;
			for(int j = vNote.size() - 1;j>=0;j--) {
				if(vNote[j]->data == parentValue) {
					if(pos == 'L') {
						vNote[j]->left = createNode(childValue);
						vNote.push_back(vNote[j]->left);
					}
					else {
						vNote[j]->right = createNode(childValue);
						vNote.push_back(vNote[j]->right);
					}
					break;
				}
			}
		}
		cout<<isSumtree(root);
		cout<<endl;
		}
	return 0;
}
