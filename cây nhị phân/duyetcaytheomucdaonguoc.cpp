#include<bits/stdc++.h>
using namespace std;

#define Nothing					"mikey"

#define run() int t;cin>>t;while(t--)
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
struct Node{
    int data;
    Node* left;
    Node* right;  
};

Node* createNode(int x){
    Node* root = new Node();
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void reverseLevelOrder(Node* root) {
    stack <Node *> S;
    queue <Node *> Q;
    Q.push(root);
    while (Q.empty() == false){
        root = Q.front();
        Q.pop();
        S.push(root);
        if (root->right)
            Q.push(root->right);
        if (root->left)
            Q.push(root->left);
    }
    while (S.empty() == false){
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
main(){
    faster();
    run(){
        int n,value1,value2;
        char str;
        cin >> n >> value1 >> value2 >> str;
        vector < Node* > index;
        Node* root=createNode(value1);
        index.push_back(root);
        if(str=='L'){
            root->left=createNode(value2);
            index.push_back(root->left);
        }
        else {
            root->right=createNode(value2);
            index.push_back(root->right);
        }
        FOR(j,2,n){
            cin >> value1 >> value2 >> str;
            FORD(i,index.size()-1,0){
                if(index[i]->data == value1){
                    if(str=='L'){
                        index[i]->left = createNode(value2);
                        index.push_back(index[i]->left);
                    }
                    else {
                        index[i]->right = createNode(value2);
                        index.push_back(index[i]->right);
                    }
                    break;                    
                }
            }
        }
        reverseLevelOrder(root);
        cout<<endl;
    }
}