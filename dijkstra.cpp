#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

const int MAX_V = 301;
const int INF = 1e9;
struct edge{
    int to, cost;
};
vector<edge> G[MAX_V];
vector<int> d(MAX_V);

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d.begin(), d.end(), INF);
    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<(int)G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    int u, v, l;
    vector<edge> next;
    for(int i=0; i<m; i++){
        cin >> u >> v >> l;
        if(u==1){
            edge e; e.to = v; e.cost = l;
            next.push_back(e);
        }
        else if(v==1){
            edge e; e.to = u; e.cost = l;
            next.push_back(e);
        }
        else{
            edge e1; e1.to = v; e1.cost = l;
            G[u].push_back(e1);
            edge e2; e2.to = u; e2.cost = l;
            G[v].push_back(e2);
        }
    }
    int ans = INF;
    for(int i=0; i<(int)next.size(); i++){
        dijkstra(next[i].to);
        for(int j=0; j<(int)next.size(); j++){
            if(i==j){continue;}
            ans = min(ans, d[next[j].to] + next[i].cost + next[j].cost);
        }
        fill(d.begin(), d.end(), INF);
    }
    if(ans == INF){
        cout << "-1" << "\n";
    }
    else{
        cout << ans << "\n";
    }
    return 0;
}