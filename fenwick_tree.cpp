// Binary Indexed Tree (Fenwick Tree)
template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n): n(n), d(n+1) {}

    void add(int i, T x=1){
        for(i++; i<=n; i+=i&-i){
            d[i] += x;
        }
    }

    void sum(int i){
        T x = 0;
        for(i++; i>0; i-=i&-i){
            x += d[i];
        }
        return x;
    }
}