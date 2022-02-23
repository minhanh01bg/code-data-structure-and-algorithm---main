#include <iostream>
#include <set>
#include <queue>
#include <climits>
#include<bits/stdc++.h>
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define NOTHING                                                    "mikey"
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define run() int t;cin>>t;while(t--)
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long 
#define reset(C) memset(C,0,sizeof(C))
#define endl "\n" 
#define N 8
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
 
using namespace std;

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= N) {
        return false;
    }
 
    return true;
}
struct Node {
    int x, y, dist;
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
    bool operator<(const Node& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
 
int BFS(Node src, Node dest) {
    set<Node> visited;
    queue<Node> q;
    q.push(src);

    while (!q.empty()){
        Node node = q.front();
        q.pop();
 
        int x = node.x;
        int y = node.y;
        int dist = node.dist;
        if (x == dest.x && y == dest.y) {
            return dist;
        }
        if (!visited.count(node)){
            visited.insert(node);
            FOR(i,0,7){
                int x1 = x + row[i];
                int y1 = y + col[i];
 
                if (isValid(x1, y1)) {
                    q.push({x1, y1, dist + 1});
                }
            }
        }
    }
    return -1;
}
 
int main() {
    faster()
    run(){
        string str1;
        cin>>str1;
        int x,y;
        
        if(str1[0]>='a'&&str1[0]<='z'){
            if(str1[0]=='a')    x=0;  
            if(str1[0]=='b')    x=1;    
            if(str1[0]=='c')    x=2;
            if(str1[0]=='d')    x=3;      
            if(str1[0]=='e')    x=4;       
            if(str1[0]=='f')    x=5;         
            if(str1[0]=='g')    x=6;        
            if(str1[0]=='h')    x=7;  
            y=str1[1]-'0' - 1;
        }
        Node src={x, y};
        string str2;
        cin>>str2;
        int z,t;
        if(str2[0]>='a'&&str2[0]<='z'){
            if(str2[0]=='a')    z=0;
            if(str2[0]=='b')    z=1;
            if(str2[0]=='c')    z=2;
            if(str2[0]=='d')    z=3;
            if(str2[0]=='e')    z=4;
            if(str2[0]=='f')    z=5; 
            if(str2[0]=='g')    z=6;
            if(str2[0]=='h')    z=7;
            t=str2[1]-'0' - 1;
        }
        Node dest = {z, t};
        cout << BFS(src, dest) << endl;
    }
    return 0;
}