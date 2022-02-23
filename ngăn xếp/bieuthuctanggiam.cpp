/* code by vu minh anh */\
#include <bits/stdc++.h>
// #define ll long long
// #define FOR(i, a, b) for (ll i = a; i <= b; i++)
// #define FORD(i, a, b) for (ll i = a; i >= b; i--)
#define run() int t;cin>>t;while(t--)
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;
void printLeast(string arr) {
    int min_avail = 1, pos_of_I = 0;
 
    vector<int>v;
 
    if (arr[0]=='I') {
        v.push_back(1);
        v.push_back(2);
        min_avail = 3;
        pos_of_I = 1;
    }
    else
    {
        v.push_back(2);
        v.push_back(1);
        min_avail = 3;
        pos_of_I = 0;
    }
 
    for (int i=1; i<arr.length(); i++)
    {
        if (arr[i]=='I')
        {
            v.push_back(min_avail);
            min_avail++;
            pos_of_I = i+1;
        }
        else
        {
            v.push_back(v[i]);
            for (int j=pos_of_I; j<=i; j++)
                v[j]++;
 
            min_avail++;
        }
    }
    for (int i=0; i<v.size(); i++)
        cout << v[i];
    cout << endl;
}
 
int main(){
	fast();
	run() {
		string str;
		cin >> str;
		printLeast(str);
	}
}
/*
abibe by:tôn trọng
agreement:sự đồng ý, hợp đồng
assurance:bảo đảm
cancellation:sự bãi bỏ,hủy bỏ
determine: quyết định,xác định
engage: tham gia,cam kết
establish:thiết lập,thành lập,xác minh
*/

/*
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int index = 0, lowlink = 0;
    bool on_stack = false;
    vector<int> ke;
};
//kiểm tra tính liên thông mạnh của đồ thị 
typedef vector<node> graph;

void dfs(int u, int &result, int &index, vector<int> &stack, graph &g) {
    index += 1;
    g[u].lowlink = g[u].index = index;
    stack.push_back(u);
    g[u].on_stack = true;

    for (int v: g[u].ke) {
        if (!g[v].index) {
            dfs(v, result, index, stack, g);
            g[u].lowlink = min(g[u].lowlink, g[v].lowlink);
        } else if (g[v].on_stack) {
            g[u].lowlink = min(g[u].lowlink, g[v].index);
        }
    }

    if (g[u].lowlink == g[u].index) {
        result += 1;
        int v;
        do {
            v = stack.back();
            stack.pop_back();
            g[v].on_stack = false;
        } while (v != u);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, m; cin >> n >> m;
		graph g(n);
		while (m--) {
			int u, v; cin >> u >> v;
			u -= 1, v -= 1;
			g[u].ke.push_back(v);
		}
		int index(0), result(0);
		vector<int> stack;
		for (int i=0; i<n; i++) {
			if (!g[i].index) dfs(i, result, index, stack, g);
		}
		if(result==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
    return 0;
}*/
/*
abibe by:tôn trọng
agreement:sự đồng ý, hợp đồng
assurance:bảo đảm
cancellation:sự bãi bỏ,hủy bỏ
determine: quyết định,xác định
engage: tham gia,cam kết
establish:thiết lập,thành lập,xác minh
*/