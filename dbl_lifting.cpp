#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000 + 1;
const int l2 = 16;

int n, q;
vector<int> g[maxn];

int parent[maxn], upj[maxn][l2];

void dfs(int u, int p) {
    parent[u] = p;

    for (int v : g[u]) {
        if (v == p) {
            continue;
        }

        dfs(v, u);
    }
}

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

int kthAncestor(int u, int k) {
    for(int i = 0; i <= l2; i++) {
        if((1<<i) & k == 0) continue;
        u = upj[u][i];
    }
    return u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0);

    buildUp();

    while (q--) {
        int u, k;
        cin >> u >> k;

        cout << kthAncestor(u, k) << endl;
    }

    return 0;
}
