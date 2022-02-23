#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define EL printf("\n")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a) memset(a, 0, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define run() int t;cin>>t;while(t--)
#define endl "\n"
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/*
struct Node{
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
}*/
int U, V;
int x=false,ok[1001];

void init(){
    FOR(i,1,U)
        ok[i]=false;
    x=false;
}

int d[1001][1001];
void DFS(int u){
    ok[u]=true;
    FOR(i,1,U){
        if(d[u][i] && ok[i]==false){
            DFS(i);
        }
        else if(d[u][i] && ok[i]==true){  
            x=true;
        }   
    }
    ok[u]=2;
}
bool inspect(){
    FOR(i,1,U){
        DFS(i);
        if(x==true) return true;
    }
    return false;
}
int main(){
    fast()
    run(){
        cin >> U >> V;
        int z,y;
        init();
        memset(d,0,sizeof(d));
        FOR(i,1,V){
            cin >> z >> y;
            d[z][y]=1;
        }
        if(inspect()) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
    return EXIT_SUCCESS;
}