#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n = 6, r = 2;
    vector<int> v{1, 2, 3, 4, 5, 6};
    string bitmask(r, 1);
    bitmask.resize(n, 0);
    do{
        for(int i=0; i<n; i++){
            if (bitmask[i]){
                cout << i << " ";
            }
        }
        cout << "\n";
    } while (prev_permutation(bitmask.begin(), bitmask.end()));
    return 0;
}