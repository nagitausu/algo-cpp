#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long int;
const ll INF = 1e18;

template<typename Monoid>
struct SegmentTree {
  using F = function<Monoid(Monoid, Monoid)>;
 
  int sz;
  vector< Monoid > seg;
 
  const F f;
  const Monoid M1;
 
  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1) {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }
 
  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }
 
  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }
 
  Monoid query(int a, int b) {
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }
 
  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }
};

int main(){
    ll n, x; cin >> n >> x;
    vector<ll> a(n);
    SegmentTree<ll> seg(n*2, [](ll a, ll b) {return min(a, b);}, INF);
    for(int i=0; i<n; i++){
        cin >> a[i];
        seg.update(i, a[i]);
        seg.update(i+n, a[i]);
    }
    ll ans = INF;
    for(int k=0; k<n; k++){
        ll val = 0;
        for(int i=0; i<n; i++){
            val += seg.query(n+i-k, n+i+1);
        }
        ans = min(ans, val + x*k);
    }
    cout << ans << endl;
    return 0;
}