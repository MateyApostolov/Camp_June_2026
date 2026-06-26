#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
const int l2 = 16;
int n, q;
int d[maxn], c[maxn];

int parent[maxn], upj[maxn][l2 + 1];

void buildUp() {
    for(int i = 1; i <= n; i++) {
        upj[i][0] = parent[i];
    }
    for(int k = 1; k <= l2; k++) {
         for(int i = 1; i <= n; i++) {
                 upj[i][k] = upj[upj[i][k - 1]][k -1];
            }
    }
}

int nxt(int u, int lit) {
    for(int i = 0; i <= l2; i++) {
        if(upj[u][i] > lit) continue;
        u = upj[u][i];
    }
    return u;
}

void find_bf () {
    stack <int> bf;
    bf.push(d[0]);
    for(int i = 1; i < n; i++) {
        while(bd[i] <= bf.top()) {
            bf.pop();
        }
        parent[bf.top()] = bd[i];
        bf.push(bd[i]);
        stack <int> help = bf;
        while(!help.empty()) {
            cout << help.top() << '-';
            help.pop();
        }
        cout << '\n';
    }
}

int main () {
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> d[i] >> c[i];
    }
    find_bf();
    for(int i = 0; i < q; i++) {
        int r, v;
        cin >> r >> v;
        cout << nxt(r, v) << '\n';
    }
    buildUp();

    return 0;
}
