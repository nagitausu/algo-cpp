#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_V = 100010;
const int MAX_LOG_V = 17;
vector<int> G[MAX_V];
int root = 0;

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];
 
void dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i=0; i<(int)G[v].size(); i++){
        if (G[v][i] != p) dfs(G[v][i], v, d+1);
    }
}

void init(int V){
    dfs(root, -1, 0);
    // initialize parent
    for(int k=0; k < MAX_LOG_V-1; k++){
        for(int v=0; v<V; v++){
            if (parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u, v);
    for(int k=0; k<MAX_LOG_V; k++){
        if((depth[v] - depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    if(u == v) return u;
    for(int k = MAX_LOG_V - 1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int main(){
    int n; cin >> n;
    int x, y;
    for(int i=0; i<n-1; i++){
        cin >> x >> y;
        G[x-1].push_back(y-1);
        G[y-1].push_back(x-1);
    }
    init(n);
    int q; cin >> q;
    int a, b;
    for(int i=0; i<q; i++){
        cin >> a >> b;
        cout << depth[a-1] + depth[b-1] - depth[lca(a-1, b-1)]*2 + 1 << "\n";
    }
    return 0;
}