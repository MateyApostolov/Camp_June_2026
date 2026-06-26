#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;
int brw[maxn][maxn], vis[maxn][maxn];
vector <pair<int, int>> kc;
pair<int, int> p[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void bfs(int x, int y) {
    brw[x][y]++;
    vis[x][y] = -1;
    for(int i = 0; i < 4; i++) {
        int px = x + p[i].first;
        int py = y + p[i].second;
        if(vis[px][py] == -1) continue;
        bfs(px, py);
    }
    return;
}

int main () {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        kc.push_back({x, y});
    }
    for(int r = 0; r <= n; r++) {
        vis[r][0] = -1;
    }
    for(int c = 0; c <= m; c++) {
        vis[0][c] = -1;
    }
    for(int r = 0; r <= n; r++) {
        vis[r][maxn] = -1;
    }
    for(int c = 0; c <= m; c++) {
        vis[maxn][c] = -1;
    }
    bfs(1, 1);
    for(int r = 0; r <= n; r++) {
        for(int c = 0; c <= m; c++) {
            cout << vis[r][c] << '-' << brw[r][c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
