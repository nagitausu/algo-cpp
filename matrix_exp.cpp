#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;
const int MOD = 1e9+7;

vector<vector<ll>> mat_mul(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2){
    int n = int(mat1[0].size());
    vector<vector<ll>> mat3(n, vector<ll>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                mat3[i][j] = mat3[i][j] + mat1[i][k] * mat2[k][j];
                mat3[i][j] %= MOD;
            }
        }
    }
    return mat3;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> &mat1, ll k){
    int n = int(mat1[0].size());
    vector<vector<ll>> mat2(n, vector<ll>(n, 0));
    for(int i=0; i<n; i++){mat2[i][i] = 1;}
    while(k > 0){
        if(k & 1){mat2 = mat_mul(mat1, mat2);}
        mat1 = mat_mul(mat1, mat1);
        k >>= 1LL;
    }
    return mat2;
}

void mat_print(vector<vector<ll>> &mat1){
    for(auto& line:mat1){
        for(auto& v:line){
            cout << v << " ";
        }
        cout << "\n";
    }
}
