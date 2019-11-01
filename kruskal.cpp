#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;

struct edge {
    ll u;
    ll v;
    ll cost;
};

vector<edge> es;
ll V, E;

// Union Find
struct UnionFind {
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) { }
    bool unionSet(ll x, ll y) {
        x = root(x);
        y = root(y);

        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y) { return root(x) == root(y); }
    ll root(ll x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    ll size(ll x) { return -data[root(x)]; }
};

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

ll kruskal(int n) {
    sort(es.begin(), es.end(), comp);
    UnionFind uf = UnionFind(V);
    ll res = 0;

    for (ll i=0; i<E; ++i) {
        edge e = es[i];
        if (!uf.findSet(e.u, e.v)) {
            uf.unionSet(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}