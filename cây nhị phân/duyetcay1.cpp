#include<bits/stdc++.h>

#define run() int t;cin>>t;while(t--)
#define endl "\n"
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int N = 50000 + 5;
int n, pre[N], in[N], pIn[N];

void construct(int a, int b, int n) {
	if(n == 0) return;
	int pos = pIn[pre[a]];
	construct(a + 1, b, pos - b);
	construct(a + 1 + pos - b, pos + 1, b + n - pos - 1);
	cout<<pre[a]<<" ";
}
 
void enter() {
	cin>>n;
    for(int i = 0; i < n; ++i) {
		cin>>in[i];
		pIn[in[i]] = i;
	}
	for(int i = 0; i < n; ++i)
		cin>>pre[i];
	
}
 
int main() {
    fast()
    run(){
	    enter();
	    construct(0, 0, n);
        cout<<"\n";
    }
	return 0;
}