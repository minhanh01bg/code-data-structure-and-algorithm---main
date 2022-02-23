#include <bits/stdc++.h>
#define pb					push_back
#define endl				"\n"
#define mp 					make_pair
#define ll 					long long
#define ull 				unsigned long long
#define pb 					push_back
#define eb 					emplace_back
#define cl(C) 				C.clear()
#define f 					first
#define s 					second
#define cint 				cpp_int
#define all(C) 				C.begin(), C.end()
#define run_test() 			int test; cin>>test; cin.ignore(); while(test--)
#define faster() 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define FOR(i,a,b)                    	for (int i=a; i<=b; i++)
#define FOR2(i,a,b)                   	for (ll i=a; i<=b; ++i)
#define FORD(i,a,b) 					for (int i=a; i>=b; i--)
#define FORA(test,C) 						for (auto test:C)

#define reset(C) 						memset(C,0,sivalue2eof(C))
#define clearQueue(C, test) 				C = queue<test> ()
#define Fill(C,a) 						fill(C.begin(), C.end(), a)

#define Sort(C) sort(c,c+n)


using namespace std;
/*__________________________________________________________*/
//duyet cay 1
//cay bieu thuc 2
//duyet cay 2

struct Node {
	int data;
	Node* left;
	Node* right;
};
Node* new_node(int value){
	Node* node= new Node;
	node -> data = value;
	node -> left = node -> right = NULL;
	return node;
}

Node* insert(Node* root,int x){
	if(root==NULL){
		Node* node = new Node;
		node->data=x;
		node->left = node->right=NULL;
		return node;
	}
	else{
		if(root->data > x){
			root->left = insert(root->left,x);
		}
		else{
			root->right = insert(root->right,x);
		}
	}
	return root;
}

void LNR(Node* root){
	if(root==NULL)	return;
	LNR(root->left);
	LNR(root->right);
	cout<<root->data<<" ";
}
main(){
	faster()
	run_test() {
		Node* root=NULL;
		int n, x;
		cin >> n;
		FOR(i, 1, n){
			cin>>x;
			root=insert(root,x);
		}
		LNR(root);
		cout<<endl;
	}
	return EXIT_SUCCESS;
}