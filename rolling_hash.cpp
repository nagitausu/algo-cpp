#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
using ll = long long int;

struct RollingHash {
    typedef long long int_type;

    int_type base1;
    int_type base2;
    int_type mod1;
    int_type mod2;
    vector<int_type> hash1;
    vector<int_type> hash2;
    vector<int_type> pow1;
    vector<int_type> pow2;

    RollingHash() : base1(1009), base2(1007), mod1(1000000007), mod2(1000000009) {}

    void init(const string &s) {
        int n = s.size();

        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        pow1.assign(n+1,1);
        pow2.assign(n+1,1);

        for(int i=0;i<n;i++) {
            hash1[i+1] = (hash1[i]+s[i]) * base1 % mod1;
            hash2[i+1] = (hash2[i]+s[i]) * base2 % mod2;
            pow1[i+1] = pow1[i] * base1 % mod1;
            pow2[i+1] = pow2[i] * base2 % mod2;
        }
    }

    int_type get(int l,int r) {
        int_type t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
        int_type t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
        return t1 * mod2 + t2;
    }
};

int main(void) {
    int n; cin >> n;
    string s; cin >> s;
    RollingHash rh;
    rh.init(s);
    for(int l=n/2; l>0; l--){
        unordered_map<ll, int> um;
        for(int i=0; i<n-l+1; i++){
            ll hash = rh.get(i, i+l);
            auto itr = um.find(hash);
            if(itr != um.end()){
                if(i - um[hash] >= l){
                    cout << l << endl;
                    return 0;
                }
            }
            else{
                um[hash] = i;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}