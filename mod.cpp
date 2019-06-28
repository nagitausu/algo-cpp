#include <iostream>
#include <string>
using namespace std;
using ll = long long int;
ll MOD = 1e9 + 7;
const int MAX = 210000;
ll fac[MAX], facinv[MAX];

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n!=0){
        if(n & 1){
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
        n = n >> 1;
    } 
    return ret;
}

ll mod_nCr(ll n, ll r){
    if(n == 0 && r == 0){
        return 1;
    }
    if(n < r || n < 0){
        return 0;
    }
    ll tmp = facinv[n-r] * facinv[r] % MOD;
    return tmp * fac[n] % MOD;
}

int main(){
    ll w, h; cin >> w >> h;
    // Initialize n! and n!^-1 mod M
    fac[0] = 1;
    facinv[0] = 1;
    for(int i=1; i<MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        facinv[i] = facinv[i-1] * mod_pow(i, MOD-2) % MOD;
    }
    cout << mod_nCr(w+h-2, h-1) << "\n";
    return 0;
}