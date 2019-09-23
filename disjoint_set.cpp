#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long int;

class DisjointSet{
  public:
    vector<ll> par;
    vector<ll> size;
    vector<ll> rank;

    DisjointSet(ll n): par(n), size(n, 1LL){
        init(n);
    }

    void init(ll n){
        par.resize(n);
        size.resize(n);
        rank.resize(n);
        for(ll i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    void reset(ll n){
        for(ll i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
            rank[i] = 0;
        }
    }

    ll root(ll x){
        while (par[x] != x){
            x = par[x] = par[par[x]];
        }
        return x;
    }

    ll get_size(ll x){
        x = par[x] = root(x);
        return size[x];
    }

    void join(ll x, ll y){
        x = root(x);
        y = root(y);
        if(x == y){return;}

        if(rank[x] < rank[y]){swap(x, y);}
        par[y] = x;
        size[x] += size[y];
        if(rank[x] == rank[y]){rank[x]++;}
    }

    bool is_same(ll x, ll y){
        return root(x) == root(y);
    }
};

int main(void) {
    DisjointSet ds(n);
    ds.reset(n);
    ds.get_size(x);
    ds.is_same(x, y);
    ds.join(a, b);
    return 0;
}
