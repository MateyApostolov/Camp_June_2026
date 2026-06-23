#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;
const int INF = 1e9 + 1;
bool vis[maxn], done[maxn];
int h, hk;
vector<int> kom[maxn];
vector <int> graph[maxn];
int d[maxn];

void dfs(int x, int t) {
    kom[hk].push_back(x);
    vis[x] = true;
    done[x] = true;
    h = max(h, t);
    for(auto v : graph[x]) {
        if(vis[v]) continue;
        dfs(v, t + 1);
    }
    return;
}

int main () {
    int n, m, a, b, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        for(int x = 1; x <= n; x++) vis[x] = false;
        h = 0;
        dfs(i, 0);
        d[i] = h;
        if(!done[i]) hk++;
    }
    for(int i = 1; i <= n; i++) {
        cout << i << ':' << d[i] << '\n';
    }
    int minc[hk];
    for(int i = 0; i < hk; i++) minc[i] = INF;
    for(int i = 0; i < hk; i++) {
        for(int x = 0; x < kom[i].size(); x++) {
            minc[kom[i][x]] = min(minc[kom[i][x]], d[x]);
        }
    }
    for(int i = 0; i < hk; i++) {
        ans += minc[i];
    }
    cout << ans;
    return 0;
}
