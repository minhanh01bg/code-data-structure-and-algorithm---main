#include<bits/stdc++.h>
using namespace std;
#define Nothing					"mikey"
#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define ll long long
struct Node{
    int data;
    Node* left;
    Node* right;
};
typedef Node* tree;
tree createNode(int data){
    tree root=new Node();
    root->data=data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
int sum=0;
void sumleft(tree root){
    if(root==NULL) return;
    if(root->left!=NULL){
        if(root->left->left==NULL&&root->left->right==NULL){
            sum+=root->left->data;
        }
        else sumleft(root->left);
    }
    if(root->right!=NULL){
        sumleft(root->right);
    }
}
main(){
    faster();
    run(){
        int n,value1,value2;
        char str;
        cin >> n >> value1 >> value2 >> str;
        tree root=createNode(value1);
        vector <tree> NODE;
        NODE.push_back(root);
        if(str=='L'){
            root->left=createNode(value2);
            NODE.push_back(root->left);
        }
        else {
            root->right=createNode(value2);
            NODE.push_back(root->right);
        }
        FOR(j,2,n){
            cin >> value1 >> value2 >> str;
            FORD(i,NODE.size()-1,0){
                if(NODE[i]->data==value1){
                    if(str=='L'){
                        NODE[i]->left= createNode(value2);
                        NODE.push_back(NODE[i]->left);
                    }
                    else {
                        NODE[i]->right= createNode(value2);
                        NODE.push_back(NODE[i]->right);
                    }
                    break;
                }
            }    
        }
        sumleft(root);
        cout << sum <<endl;
        sum=0;        
    }
    return EXIT_SUCCESS;
}