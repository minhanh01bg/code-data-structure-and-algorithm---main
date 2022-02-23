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
#define reset(x) memset(x,0,sizeof((x)))

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
#define reset(x) memset(x,0,sizeof((x)))

// struct Node{
//     int data;
//     Node *left;
//     Node *right;
// };
// struct Node* newNode(int data)
// {
//     struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//     node->data = data;
//     node->left = node->right = NULL;
//     return node;
// }
// bool checkUtil(struct Node *root, int level, int *leafLevel){
//     if (root == NULL) return true;
 
//     if (root->left == NULL &&
//         root->right == NULL) {
//         if (*leafLevel == 0) {
//             *leafLevel = level; // Set first found leaf's level
//             return true;
//         }
//         return (level == *leafLevel);
//     }
//     return checkUtil(root->left, level + 1, leafLevel) && checkUtil(root->right, level + 1, leafLevel);
// }
 
// bool check(struct Node *root) {
//     int level = 0, leafLevel = 0;
//     return checkUtil(root, level, &leafLevel);
// }

ll notLeaf[1001], left1[1001], right1[1001], index1[1001];

void Setup(ll y, ll a) {
	index1[y] = a;
	if (left1[y] != 0) Setup(left1[y], a + 1);
	if (right1[y] != 0) Setup(right1[y], a + 1);
}
 
void addRight(ll x, ll y) {
	right1[x] = y;
	if (index1[x] == 0) index1[x] = 1;
	index1[y] = index1[x] + 1;
	notLeaf[x] = 1;
	Setup(y,index1[y]);
}
 
void addLeft(ll x, ll y) {
	left1[x] = y;
	if (index1[x] == 0) index1[x] = 1;
	index1[y] = index1[x] + 1;
	notLeaf[x] = 1;
	Setup(y,index1[y]);
}
 /*----------------------------------------------------------------*/
ll notLeaf1[1001], left11[1001], right11[1001], index11[1001];

void Setup1(ll y, ll a) {
	index11[y] = a;
	if (left11[y] != 0) Setup(left11[y], a + 1);
	if (right11[y] != 0) Setup(right11[y], a + 1);
}
void addRight1(ll x, ll y) {
	right11[x] = y;
	if (index11[x] == 0) index11[x] = 1;
	index11[y] = index11[x] + 1;
	notLeaf1[x] = 1;
	Setup(y,index11[y]);
}
 
void addLeft1(ll x, ll y) {
	left11[x] = y;
	if (index11[x] == 0) index11[x] = 1;
	index11[y] = index11[x] + 1;
	notLeaf1[x] = 1;
	Setup(y,index11[y]);
}
int main() {
	fast()
	run() {
		ll a;
		cin >> a;
		reset(notLeaf);
		reset(left1);
		reset(right1);
		reset(index1);
        reset(notLeaf1);
		reset(left11);
		reset(right11);
		reset(index11);
		while(a--) {
			ll x,y;
			char token;
			cin>>x>>y>>token;
			if (token == 'R') addRight(x,y);
			if (token == 'L') addLeft(x,y);
        }int x=0;
        int z;cin>>z;
        while(z--) {
			ll x,y;
			char token;
			cin>>x>>y>>token;
			if (token == 'R') addRight1(x,y);
			if (token == 'L') addLeft1(x,y);
        }
		ll counting = 0;
		ll token = 0;
        
		FOR(i,0,1000) {
            if(notLeaf[i] && (left1[i]!=left11[i]||right1[i]!=right11[i])){
                x=1;
            }
		}
		if(x==0)
            cout<<"1";
        else cout<<"0";
		cout<<endl;
	}
}

/*
void Try(int i,ll ans,ll Uoc){
    if(Uoc>n) return;
    if(Uoc==n) res=min(res,ans);
    for(int j=1;;j++){
        if(ans>res) break;
        ans*=prime[i];
        Try(i+1,ans,Uoc*(j+1));
    }
}
int main(){
    fast()
    run(){
        cin>>n;
        res=1e18;
        Try(0,1,1);
        cout<<res<<endl;
    }
    return EXIT_SUCCESS;
}*/
/*
long long u =1e9 +7, k; int n;
int MOD=1e9+7;
int DIM=2;
struct matrix{
	ll a[11][11];
};
matrix operator*(matrix A, matrix B) {
    matrix C;
    FOR(i,0,DIM-1){
        FOR(j,0,DIM-1) {
            C.a[i][j] = 0;
            FOR(t,0,DIM-1)
                C.a[i][j] = (C.a[i][j] + (A.a[i][t] * B.a[t][j])%MOD) %MOD;
        }
    }
    return C;
}
matrix pow_matrix(matrix a, int n) {
    if (n == 1) return a;
    matrix b = pow_matrix(a, n / 2);
    if (n & 1) return b * b * a;
    return b*b;
}
int main(){
	int t;
	cin >> t;
    int k;
	while(t--){
		cin >> k;
		matrix x, y;
        x.a[0][0]=1;
        x.a[0][1]=1;
        x.a[1][0]=1;
        x.a[1][1]=0;
        y=pow_matrix(x,k);
        cout<<y.a[0][1]<<endl;
    }	
	return EXIT_SUCCESS;
}*/
/*
int main(){
    fast()
    run(){
        int n;
        cin>>n;
        int a[n];
        FOR(i,0,n-1)
            cin>>a[i];
        int list[n];
        FOR(i,0,n-1) 
            list[i]=a[i];
        FOR(i,1,n-1)
            FOR(j,0,i)
                if(a[i] > a[j]&&list[i] < list[j]+a[i])
                    list[i]=list[j]+a[i];
        int d[n];
        FOR(i,0,n-1) d[i]=a[i];
        FORD(i,n-2,0)
            FORD(j,n-1,i+1)
                if(a[i] > a[j] && d[i] < d[j]+a[i])
                    d[i]=d[j]+a[i];
        int Max=0;
        FOR(i,0,n-1){
            Max=max(Max,list[i]+d[i]-a[i]);
        }
        cout<<Max<<endl;
    }
}*/