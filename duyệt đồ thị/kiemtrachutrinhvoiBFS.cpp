#include<bits/stdc++.h>
#define ll long long
// test 
#define run() int t;cin>>t;while(t--) 
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);
// acronym 
#define pob pop_back 
#define EL printf("\n") 
#define pb push_back 
#define FOR(i,l,r) for (int i=l;i<=r;i++) 
#define FORD(i,r,l) for (int i=r;i>=l;i--) 
using namespace std;
class Graph{ 
    int V; 
    list<int> *adj; 
    bool isCyclicUtil(int v, bool visited[],int parent);
public: 
    Graph(int V); 
    void add(int u, int v); 
    bool isCyclic();
};

Graph::Graph(int V){ 
    this->V = V; 
    adj = new list<int>[V];
}

void Graph::add(int u,int v){ 
    adj[v].pb(u); 
    adj[u].pb(v);
}

bool Graph::isCyclicUtil(int v,bool visited[],int parent){ 
    visited[v]=true; 
    list<int>::iterator i; 
    for(i= adj[v].begin();i!=adj[v].end();i++){ 
        if(!visited[*i]){ 
            if(isCyclicUtil(*i, visited, v)) 
                return true; 
        } 
        else if(*i != parent) 
            return true; 
    } 
    return false;
}

bool Graph::isCyclic(){ 
    bool *visited = new bool [V]; 
    FOR(i,0,V-1) 
    visited[i]=false; 
    FOR(u,0,V-1){ 
        if(!visited[u]) 
            if(isCyclicUtil(u,visited,-1)) 
                return true; 
    } 
    return false;
}

int main(){ 
    fast(); 
    run(){ 
        int U,V; 
        cin >> U >> V; 
        int u,v; 
        Graph g1(U); 
        FOR(i,0,V-1) {
            cin >> u >> v; 
            g1.add(u-1,v-1); 
        } 
        g1.isCyclic() ? cout<<"YES\n":cout<<"NO\n"; 
    }
    return EXIT_SUCCESS;
}