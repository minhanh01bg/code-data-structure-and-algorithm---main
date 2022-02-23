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
 
int main() {
	fast()
	run() {
		ll a;
		cin >> a;
		reset(notLeaf);
		reset(left1);
		reset(right1);
		reset(index1);
		while(a--) {
			ll x,y;
			char token;
			cin>>x>>y>>token;
			if (token == 'R') addRight(x,y);
			if (token == 'L') addLeft(x,y);
        }
		ll counting = 0;
		ll token = 0;
        int x=0;
		FOR(i,0,1000) {
            if(notLeaf[i]&&(left1[i]==0||right1[i]==0)){
                x=1;
            }
			if (notLeaf[i]) continue;
			if (!index1[i]) continue;
			if (token != index1[i]) {
				token = index1[i];
				counting++;
			}
		}
		if(x==0&&counting == 1)
            cout<<"Yes";
        else cout<<"No";
		cout<<endl;
	}
}