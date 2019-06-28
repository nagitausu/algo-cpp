#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long int;
const int INF = 1e9;

int main(){
    int q; cin >> q;
    int id, a, b;
    ll ans = 0LL;

    // Get median with 2 priority_queue
    priority_queue<int> pq_lft;
    priority_queue<int, vector<int>, greater<int>> pq_rgt;
    pq_lft.push(-INF); pq_rgt.push(INF);
    for(int i=0; i<q; i++){
        cin >> id;
        // Update query
        if(id == 1){
            cin >> a >> b;
            // Add bias
            ans += b;
            // Insert a
            if(pq_lft.size() == pq_rgt.size()){
                if(a < pq_rgt.top()){
                    if(a < pq_lft.top()){
                        ans += pq_lft.top() - a;
                    }
                    pq_lft.push(a);
                }
                else{
                    ans += a - pq_rgt.top();
                    pq_rgt.push(a);
                    pq_lft.push(pq_rgt.top()); pq_rgt.pop();
                }
            }
            else{
                ans += abs(pq_lft.top() - a);
                if(a > pq_lft.top()){
                    pq_rgt.push(a);
                }
                else{
                    pq_lft.push(a);
                    pq_rgt.push(pq_lft.top()); pq_lft.pop();
                }
            }
        }
        // Get query
        if(id == 2){
            cout << pq_lft.top() << " " << ans << endl;
        }
    }
    return 0;
}