#include<iostream>
#include<vector>

using namespace std;

class UF {
    
private:
    vector<int> parent;
    vector<int> rank;
    int count;
    int N;
    
    bool validate(int p) {
        return (p > 0 && p <= N);
    }
    
public:
    
    UF(int N) : parent(N), rank(N, 0), N(N), count(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    
    int find(int p) {
        if (!validate(p)) return -1;
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];    // path compression by halving
            p = parent[p];
        }
        return p;
    }
    
    int getCount() {
        return count;
    }
    
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
    
    void Union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;
        
        // make root of smaller rank point to root of larger rank
        if (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
        else if (rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
        else {
            parent[rootQ] = rootP;
            rank[rootP]++;
        }
        count--;
    }
    
    ~UF() {}
};

int main() {
    UF uf(5);
    cout << uf.getCount() << endl;
    cout << uf.connected(2, 4) << endl;
    uf.Union(1, 2);
    uf.Union(3, 4);
    cout << uf.getCount() << endl;
    uf.Union(1, 3);
    cout << uf.connected(2, 4) << endl;
}
